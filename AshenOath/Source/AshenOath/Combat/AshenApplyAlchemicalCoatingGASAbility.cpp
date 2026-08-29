// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenApplyAlchemicalCoatingGASAbility.h"
#include "Combat/AshenAlchemicalSlagConvergenceSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UAshenApplyAlchemicalCoatingGASAbility::UAshenApplyAlchemicalCoatingGASAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	CoatingToApply = EAlchemicalBladeCoating::PyrophoricNaphtha;
	ApplicationCharges = 5;
}

void UAshenApplyAlchemicalCoatingGASAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}

	if (Avatar)
	{
		if (UWorld* World = Avatar->GetWorld())
		{
			if (UAshenAlchemicalSlagConvergenceSubsystem* SlagSubsystem = World->GetSubsystem<UAshenAlchemicalSlagConvergenceSubsystem>())
			{
				SlagSubsystem->ApplyCoating(CoatingToApply, ApplicationCharges);
			}
		}

		// Update weapon coating emissive on character dynamic materials
		if (ACharacter* Character = Cast<ACharacter>(Avatar))
		{
			if (USkeletalMeshComponent* MeshComp = Character->GetMesh())
			{
				FLinearColor CoatingColor = FLinearColor::White;
				switch (CoatingToApply)
				{
				case EAlchemicalBladeCoating::PyrophoricNaphtha:
					CoatingColor = FLinearColor(1.0f, 0.35f, 0.05f, 1.0f); // Flame Orange
					break;
				case EAlchemicalBladeCoating::GlacialFrostResin:
					CoatingColor = FLinearColor(0.25f, 0.75f, 1.0f, 1.0f); // Frost Cyan
					break;
				case EAlchemicalBladeCoating::VitriolAcid:
					CoatingColor = FLinearColor(0.40f, 0.95f, 0.15f, 1.0f); // Corrosive Green
					break;
				case EAlchemicalBladeCoating::ConductiveCopperSalve:
					CoatingColor = FLinearColor(0.85f, 0.55f, 0.15f, 1.0f); // Copper Bronze
					break;
				default:
					CoatingColor = FLinearColor(0.1f, 0.1f, 0.1f, 0.0f);
					break;
				}

				const int32 NumMats = MeshComp->GetNumMaterials();
				for (int32 i = 0; i < NumMats; ++i)
				{
					if (UMaterialInstanceDynamic* MID = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(i)))
					{
						MID->SetVectorParameterValue(TEXT("WeaponCoatingColor"), CoatingColor);
						MID->SetScalarParameterValue(TEXT("WeaponCoatingActive"), 1.0f);
					}
				}
			}
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UAshenApplyAlchemicalCoatingGASAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
