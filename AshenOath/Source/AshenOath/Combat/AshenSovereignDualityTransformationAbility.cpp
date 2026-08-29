// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSovereignDualityTransformationAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "World/AshenCorruptionMaskInterpolator.h"
#include "World/AshenDiegeticVisualCorruptionSubsystem.h"
#include "Soul/AshenDualityStateVectorCompiler.h"
#include "World/AshenDualityShaderShiftComponent.h"
#include "World/AshenDualityEngineShaderModulator.h"
#include "World/AshenDualityMaterialInstanceAdapterComponent.h"
#include "World/AshenDualityPostProcessVolumeAdapter.h"
#include "World/AshenDualityTransformationLocusActor.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UAshenSovereignDualityTransformationAbility::UAshenSovereignDualityTransformationAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	TransformationPulseRadius = 1000.0f;
	PulsePoiseDamage = 120.0f;
	PulseBaseDamage = 85.0f;
}

void UAshenSovereignDualityTransformationAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	TriggerDualityTransformationPulse();

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UAshenSovereignDualityTransformationAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

bool UAshenSovereignDualityTransformationAbility::TriggerDualityTransformationPulse()
{
	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}
	if (!Avatar)
	{
		return false;
	}

	AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Avatar);
	UWorld* World = Avatar->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Toggle & drive corruption state transition
	float TargetCorruption = 1.0f;
	if (CombatChar)
	{
		const float CurrentCorr = CombatChar->GetCorruptionAmount();
		const bool bBecomingDark = (CurrentCorr < 0.5f);
		TargetCorruption = bBecomingDark ? 1.0f : 0.0f;
		CombatChar->TransitionCorruptionState(bBecomingDark);

		// Route authoritative state vector compilation (Soul Domain)
		if (UAshenDualityStateVectorCompiler* Compiler = CombatChar->GetDualityStateVectorCompiler())
		{
			Compiler->CompileDualityStateVector(TargetCorruption);
		}

		// Fan out to World Domain adapters
		if (UAshenDualityShaderShiftComponent* ShaderShift = CombatChar->GetDualityShaderShiftComponent())
		{
			ShaderShift->SetDualityBlendRatio(TargetCorruption);
		}
		if (UAshenDualityEngineShaderModulator* ShaderMod = CombatChar->GetDualityEngineShaderModulator())
		{
			ShaderMod->UpdateDualityShaderParameters(TargetCorruption);
		}
		if (UAshenDualityMaterialInstanceAdapterComponent* MatAdapter = CombatChar->GetDualityMaterialInstanceAdapter())
		{
			MatAdapter->UpdateMaterialInstanceParameters(TEXT("DualityBlendRatio"), TargetCorruption);
		}
		if (UAshenDualityPostProcessVolumeAdapter* PPAdapter = CombatChar->GetDualityPostProcessAdapter())
		{
			PPAdapter->AdjustPostProcessForRealmShift(TargetCorruption);
		}
	}

	// 2. Calculate channel-packed corruption mask values (R=Soot, G=Grime, B=Raggedness, A=Emissive)
	UAshenCorruptionMaskInterpolator* MaskInterp = NewObject<UAshenCorruptionMaskInterpolator>(Avatar);
	const FAshenCorruptionMaskValues MaskValues = MaskInterp ? MaskInterp->CalculateCorruptionMaskChannelValues(TargetCorruption) : FAshenCorruptionMaskValues();

	// 3. Modulate dynamic material instances across character skeletal mesh
	if (ACharacter* Character = Cast<ACharacter>(Avatar))
	{
		if (USkeletalMeshComponent* MeshComp = Character->GetMesh())
		{
			const int32 NumMats = MeshComp->GetNumMaterials();
			for (int32 i = 0; i < NumMats; ++i)
			{
				if (UMaterialInstanceDynamic* MID = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(i)))
				{
					MID->SetScalarParameterValue(TEXT("CorruptionAmount"), TargetCorruption);
					MID->SetScalarParameterValue(TEXT("ArmorSootR"), MaskValues.ArmorSootR);
					MID->SetScalarParameterValue(TEXT("SeamGrimeG"), MaskValues.SeamGrimeG);
					MID->SetScalarParameterValue(TEXT("TabardRaggednessB"), MaskValues.TabardRaggednessB);
					MID->SetScalarParameterValue(TEXT("EyeBladeEmissiveA"), MaskValues.EyeBladeEmissiveA);
					MID->SetScalarParameterValue(TEXT("DualityBlendRatio"), TargetCorruption);
				}
			}
		}
	}

	// 4. Modulate visual corruption world subsystem for post-process lens and aberration
	if (UAshenDiegeticVisualCorruptionSubsystem* VisualSubsystem = World->GetSubsystem<UAshenDiegeticVisualCorruptionSubsystem>())
	{
		VisualSubsystem->ModulateVisualCorruptionForTrauma(TargetCorruption * 100.0f);
	}

	// 5. Trigger environmental Duality Transformation Locus Actors within range
	for (TActorIterator<AAshenDualityTransformationLocusActor> It(World); It; ++It)
	{
		if (FVector::DistSquared(Avatar->GetActorLocation(), It->GetActorLocation()) <= FMath::Square(TransformationPulseRadius))
		{
			It->TriggerDualityTransformationAuraPulse();
		}
	}

	// 6. Radial pulse damage and stagger sweep
	TArray<AActor*> IgnoredActors;
	IgnoredActors.Add(Avatar);

	UGameplayStatics::ApplyRadialDamageWithFalloff(
		World,
		PulseBaseDamage,
		PulseBaseDamage * 0.35f,
		Avatar->GetActorLocation(),
		TransformationPulseRadius * 0.25f,
		TransformationPulseRadius,
		1.0f,
		UDamageType::StaticClass(),
		IgnoredActors,
		Avatar,
		nullptr
	);

	if (CombatChar)
	{
		CombatChar->TriggerStrikeImpact();
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignDualityTransformationAbility: Executed full Duality Transformation Pulse to target corruption %.2f across materials and world subsystems."), TargetCorruption);
	return true;
}
