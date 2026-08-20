// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeLightingTensionAdapter.h"

UAshenGenerativeLightingTensionAdapter::UAshenGenerativeLightingTensionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeLightingTensionAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SkyLightIntensityScalar = FMath::Clamp(1.2f - (NewState.IntegrationDebt * 0.7f), 0.3f, 1.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeLightingTensionAdapter: Directional sky light intensity scalar set to %.2f"), SkyLightIntensityScalar);
}
