// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenCartographerMapViewModel.h"

UAshenCartographerMapViewModel::UAshenCartographerMapViewModel()
{
}

void UAshenCartographerMapViewModel::SetZoomLevel(EAshenMapZoomLevel NewZoomLevel)
{
	if (CurrentZoomLevel != NewZoomLevel)
	{
		EAshenMapZoomLevel PrevLevel = CurrentZoomLevel;
		CurrentZoomLevel = NewZoomLevel;
		if (OnMapZoomLevelChanged.IsBound())
		{
			OnMapZoomLevelChanged.Broadcast(PrevLevel, CurrentZoomLevel);
		}
		UE_LOG(LogTemp, Log, TEXT("UAshenCartographerMapViewModel: Map zoom level shifted to %d"), static_cast<int32>(CurrentZoomLevel));
	}
}

void UAshenCartographerMapViewModel::EvaluateSoulStateVectorParameters(float IntegrationDebt, float CorruptionAmount)
{
	ParchmentSootCoverage = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);
	InkBleedIntensity = FMath::Clamp(IntegrationDebt / 100.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCartographerMapViewModel: Evaluated PBR parameters (Soot: %f, Ink Bleed: %f)"), ParchmentSootCoverage, InkBleedIntensity);
}
