// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenNyxianBlackSapPostProcessAdapter.h"

UAshenNyxianBlackSapPostProcessAdapter::UAshenNyxianBlackSapPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	BlackSapVignetteIntensity = 0.0f;
}
void UAshenNyxianBlackSapPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNyxianBlackSapPostProcessAdapter::ApplyBlackSapVignette(float BurnoutScalar)
{
	const float B = FMath::Clamp(BurnoutScalar, 0.0f, 1.0f);
	BlackSapVignetteIntensity = (B >= 0.50f) ? (B - 0.50f) / 0.50f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenNyxianBlackSapPostProcessAdapter: Black Sap Vignette Intensity: %.2f (Burnout: %.2f)"),
		BlackSapVignetteIntensity, B);
}
