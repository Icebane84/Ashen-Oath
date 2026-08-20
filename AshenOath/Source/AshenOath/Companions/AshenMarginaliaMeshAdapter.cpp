// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenMarginaliaMeshAdapter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UAshenMarginaliaMeshAdapter::UAshenMarginaliaMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentWear = 0.0f;
}

void UAshenMarginaliaMeshAdapter::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		JournalSkeletalMesh = Owner->FindComponentByClass<USkeletalMeshComponent>();
		if (JournalSkeletalMesh && JournalSkeletalMesh->GetNumMaterials() > 0)
		{
			DynamicMaterial = JournalSkeletalMesh->CreateDynamicMaterialInstance(0);
		}
	}
}

void UAshenMarginaliaMeshAdapter::UpdateJournalWear(float WearIntensity, float SootIntensity)
{
	CurrentWear = FMath::Clamp(WearIntensity, 0.0f, 1.0f);
	if (DynamicMaterial)
	{
		DynamicMaterial->SetScalarParameterValue(FName(TEXT("CoverWear")), CurrentWear);
		DynamicMaterial->SetScalarParameterValue(FName(TEXT("SootSmudge")), FMath::Clamp(SootIntensity, 0.0f, 1.0f));
	}
}
