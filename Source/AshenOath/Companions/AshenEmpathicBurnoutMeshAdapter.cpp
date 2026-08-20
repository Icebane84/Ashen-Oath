// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenEmpathicBurnoutMeshAdapter.h"

UAshenEmpathicBurnoutMeshAdapter::UAshenEmpathicBurnoutMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	WaxySkinDesaturationScalar = 0.0f;
	CyanoticNailTintScalar = 0.0f;
}
void UAshenEmpathicBurnoutMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEmpathicBurnoutMeshAdapter::UpdateBurnoutVisuals(float BurnoutAmount)
{
	const float B = FMath::Clamp(BurnoutAmount, 0.0f, 1.0f);
	WaxySkinDesaturationScalar = B * 0.80f;
	CyanoticNailTintScalar = B;

	UE_LOG(LogTemp, Log, TEXT("UAshenEmpathicBurnoutMeshAdapter: Serafina Skin Desaturation: %.2f | Blue Nails Tint: %.2f"),
		WaxySkinDesaturationScalar, CyanoticNailTintScalar);
}
