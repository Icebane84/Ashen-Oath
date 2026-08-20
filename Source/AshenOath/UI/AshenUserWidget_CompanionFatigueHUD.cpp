// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CompanionFatigueHUD.h"

void UAshenUserWidget_CompanionFatigueHUD::UpdateFatigueHUD(float InGFatigue, float InSFatigue, float InKFatigue)
{
	GarrettFatigue = FMath::Clamp(InGFatigue, 0.0f, 1.0f);
	SerafinaFatigue = FMath::Clamp(InSFatigue, 0.0f, 1.0f);
	KaelenFatigue = FMath::Clamp(InKFatigue, 0.0f, 1.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CompanionFatigueHUD: Updated HUD -> Garrett: %.1f%%, Serafina: %.1f%%, Kaelen: %.1f%%"),
		GarrettFatigue * 100.0f, SerafinaFatigue * 100.0f, KaelenFatigue * 100.0f);
}
