// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSomaticCharacterMeshAdapter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UAshenSomaticCharacterMeshAdapter::UAshenSomaticCharacterMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	VeinMaterialParameterName = FName(TEXT("ShadowVeinIntensity"));
	CurrentVeinCreep = 0.0f;
	TargetVeinCreep = 0.0f;
	CurrentTremor = 0.0f;
	TargetTremor = 0.0f;
}

void UAshenSomaticCharacterMeshAdapter::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		SkeletalMesh = Owner->FindComponentByClass<USkeletalMeshComponent>();
		if (SkeletalMesh && SkeletalMesh->GetNumMaterials() > 0)
		{
			DynamicMaterial = SkeletalMesh->CreateDynamicMaterialInstance(0);
		}
	}
}

void UAshenSomaticCharacterMeshAdapter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentVeinCreep = FMath::FInterpTo(CurrentVeinCreep, TargetVeinCreep, DeltaTime, 3.0f);
	CurrentTremor = FMath::FInterpTo(CurrentTremor, TargetTremor, DeltaTime, 5.0f);

	if (DynamicMaterial)
	{
		DynamicMaterial->SetScalarParameterValue(VeinMaterialParameterName, CurrentVeinCreep);
	}
}

void UAshenSomaticCharacterMeshAdapter::UpdateSomaticMeshParameters(float MotorTremor, float ParasitePressure, float Corruption)
{
	TargetTremor = FMath::Clamp(MotorTremor, 0.0f, 1.0f);
	TargetVeinCreep = FMath::Clamp((Corruption * 0.60f) + (ParasitePressure * 0.40f), 0.0f, 1.0f);
}
