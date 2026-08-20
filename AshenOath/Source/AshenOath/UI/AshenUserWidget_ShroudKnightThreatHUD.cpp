// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ShroudKnightThreatHUD.h"

void UAshenUserWidget_ShroudKnightThreatHUD::UpdateThreatHUD(float ParanoiaRatio, bool bPhasing)
{
	ParanoiaMeterRatio = FMath::Clamp(ParanoiaRatio, 0.0f, 1.0f);
	bIsShroudPhasing = bPhasing;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ShroudKnightThreatHUD: Paranoia: %.1f%% | Phasing: %s"),
		ParanoiaMeterRatio * 100.0f, bIsShroudPhasing ? TEXT("ACTIVE") : TEXT("INACTIVE"));
}
