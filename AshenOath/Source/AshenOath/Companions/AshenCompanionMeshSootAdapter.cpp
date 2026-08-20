// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionMeshSootAdapter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UAshenCompanionMeshSootAdapter::UAshenCompanionMeshSootAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	MaterialScalarParameterName = FName(TEXT("EmpathicSootIntensity"));
	CurrentIntensity = 0.0f;
	TargetIntensity = 0.0f;
}

void UAshenCompanionMeshSootAdapter::BeginPlay()
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

void UAshenCompanionMeshSootAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentIntensity = FMath::FInterpTo(CurrentIntensity, TargetIntensity, DeltaTime, 3.5f);

	if (DynamicMaterial)
	{
		DynamicMaterial->SetScalarParameterValue(MaterialScalarParameterName, CurrentIntensity);
	}
}

void UAshenCompanionMeshSootAdapter::UpdateCompanionMeshScalars(float SootOrWearIntensity)
{
	TargetIntensity = FMath::Clamp(SootOrWearIntensity, 0.0f, 1.0f);
}
