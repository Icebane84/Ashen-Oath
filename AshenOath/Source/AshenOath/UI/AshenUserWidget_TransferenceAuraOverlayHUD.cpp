// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_TransferenceAuraOverlayHUD.h"

UAshenUserWidget_TransferenceAuraOverlayHUD::UAshenUserWidget_TransferenceAuraOverlayHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentBurnoutRatio = 0.0f;
	CurrentTetherIntensity = 0.0f;
	CurrentAuraDimming = 1.0f;
}

void UAshenUserWidget_TransferenceAuraOverlayHUD::UpdateTransferenceVisuals(float BurnoutRatio, float TetherIntensity)
{
	CurrentBurnoutRatio = FMath::Clamp(BurnoutRatio, 0.0f, 1.0f);
	CurrentTetherIntensity = FMath::Clamp(TetherIntensity, 0.0f, 1.0f);
	CurrentAuraDimming = FMath::Clamp(1.0f - (CurrentBurnoutRatio * 0.50f), 0.50f, 1.0f);
}
