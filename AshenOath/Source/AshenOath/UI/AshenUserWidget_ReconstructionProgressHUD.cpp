// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ReconstructionProgressHUD.h"

void UAshenUserWidget_ReconstructionProgressHUD::UpdateProgress(float InProgress, bool bActive)
{
	ProgressPercent = FMath::Clamp(InProgress, 0.0f, 1.0f);
	bIsActivelyReconstructing = bActive;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ReconstructionProgressHUD: Reconstruction HUD (Progress: %.1f%%, Active: %s)"),
		ProgressPercent * 100.0f, bIsActivelyReconstructing ? TEXT("TRUE") : TEXT("FALSE"));
}
