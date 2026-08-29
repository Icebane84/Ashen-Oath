// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_DestructionWeatherAIHUD.h"

UAshenUserWidget_DestructionWeatherAIHUD::UAshenUserWidget_DestructionWeatherAIHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedTier = EAtmosphericVisibilityTier::ClearDaylight;
	DisplayedLockOnRange = 1500.0f;
	bDisplayedConductiveWarning = false;
	bDisplayedStealthEligible = false;
}

void UAshenUserWidget_DestructionWeatherAIHUD::UpdateTacticalHUD(
	EAtmosphericVisibilityTier VisibilityTier,
	float LockOnRangeUU,
	bool bConductiveSurfaceNearby,
	bool bStealthAmbushEligible)
{
	DisplayedTier = VisibilityTier;
	DisplayedLockOnRange = LockOnRangeUU;
	bDisplayedConductiveWarning = bConductiveSurfaceNearby;
	bDisplayedStealthEligible = bStealthAmbushEligible;
}
