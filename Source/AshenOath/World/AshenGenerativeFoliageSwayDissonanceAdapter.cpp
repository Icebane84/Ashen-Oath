// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenGenerativeFoliageSwayDissonanceAdapter.h"

UAshenGenerativeFoliageSwayDissonanceAdapter::UAshenGenerativeFoliageSwayDissonanceAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGenerativeFoliageSwayDissonanceAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FoliageSwaySpeedMultiplier = 1.0f + (NewState.IntegrationDebt * 1.2f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGenerativeFoliageSwayDissonanceAdapter: Foliage sway speed multiplier set to %.2f"), FoliageSwaySpeedMultiplier);
}
