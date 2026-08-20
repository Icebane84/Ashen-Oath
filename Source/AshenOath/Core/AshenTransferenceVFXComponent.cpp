// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenTransferenceVFXComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/MeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

UAshenTransferenceVFXComponent::UAshenTransferenceVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SmoothStepT1 = 0.0f;
	SmoothStepT2 = 0.0f;
}

void UAshenTransferenceVFXComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (ACharacter* OwnerChar = Cast<ACharacter>(Owner))
	{
		if (UMeshComponent* Mesh = OwnerChar->GetMesh())
		{
			int32 NumMat = Mesh->GetNumMaterials();
			for (int32 i = 0; i < NumMat; ++i)
			{
				UMaterialInterface* Mat = Mesh->GetMaterial(i);
				if (Mat)
				{
					UMaterialInstanceDynamic* DynMat = Mesh->CreateDynamicMaterialInstance(i, Mat);
					if (DynMat)
					{
						DynamicMaterials.Add(DynMat);
					}
				}
			}
		}
	}
}

void UAshenTransferenceVFXComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UAshenTransferenceVFXComponent::SmoothStepCustom(float Edge0, float Edge1, float X) const
{
	float T = FMath::Clamp((X - Edge0) / (Edge1 - Edge0), 0.0f, 1.0f);
	return T * T * (3.0f - 2.0f * T);
}

void UAshenTransferenceVFXComponent::UpdateCorruptionVFX(float CorruptionAmount)
{
	float C = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);

	// Phase 1 (t1): smoothstep(0.00, 0.55, C) -- Eye flickering, mark opacity, seam grime
	SmoothStepT1 = SmoothStepCustom(0.00f, 0.55f, C);

	// Phase 2 (t2): smoothstep(0.35, 1.00, C) -- Armor soot infiltration, crimson ocular takeover
	SmoothStepT2 = SmoothStepCustom(0.35f, 1.00f, C);

	for (UMaterialInstanceDynamic* DynMat : DynamicMaterials)
	{
		if (DynMat)
		{
			DynMat->SetScalarParameterValue(TEXT("CorruptionAmount"), C);
			DynMat->SetScalarParameterValue(TEXT("Phase1_SmoothStep"), SmoothStepT1);
			DynMat->SetScalarParameterValue(TEXT("Phase2_SmoothStep"), SmoothStepT2);
			DynMat->SetScalarParameterValue(TEXT("OcularEmissiveIntensity"), 1.0f + (SmoothStepT2 * 5.0f));
		}
	}

	UE_LOG(LogTemp, Verbose, TEXT("UpdateCorruptionVFX: C=%.2f -> t1=%.2f, t2=%.2f"), C, SmoothStepT1, SmoothStepT2);
}

void UAshenTransferenceVFXComponent::TriggerTransferenceBurst(FVector SourceLocation, FVector TargetLocation)
{
	if (TransferenceRibbonSystem && GetWorld())
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), TransferenceRibbonSystem, SourceLocation);
	}

	UE_LOG(LogTemp, Log, TEXT("TriggerTransferenceBurst: Transference ribbon spawned %s -> %s"), *SourceLocation.ToString(), *TargetLocation.ToString());
	OnTransferenceVFXTriggered.Broadcast(SourceLocation, TargetLocation);
}

void UAshenTransferenceVFXComponent::TriggerBastionShieldImpact(FVector ImpactPoint, bool bIsDeflected)
{
	if (GetWorld())
	{
		if (bIsDeflected && DeflectionSparksSystem)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), DeflectionSparksSystem, ImpactPoint);
			UE_LOG(LogTemp, Log, TEXT("TriggerBastionShieldImpact: Deflection sparks spawned at %s"), *ImpactPoint.ToString());
		}
		else if (!bIsDeflected && ArmorFractureSystem)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ArmorFractureSystem, ImpactPoint);
			UE_LOG(LogTemp, Log, TEXT("TriggerBastionShieldImpact: Armor fracture energy spawned at %s"), *ImpactPoint.ToString());
		}
	}
}
