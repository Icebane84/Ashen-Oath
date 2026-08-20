// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MemoryBattleHUD.h"

void UAshenUserWidget_MemoryBattleHUD::UpdateMemoryBattleHUD(FName EchoID, float TraumaPercent)
{
	DisplayedEchoID = EchoID;
	TraumaMeterPercent = FMath::Clamp(TraumaPercent, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryBattleHUD: Echo '%s' Trauma Meter at %.1f%%."),
		*DisplayedEchoID.ToString(), TraumaMeterPercent * 100.0f);
}
