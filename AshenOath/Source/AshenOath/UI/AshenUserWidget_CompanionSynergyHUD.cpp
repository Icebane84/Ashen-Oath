// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CompanionSynergyHUD.h"

void UAshenUserWidget_CompanionSynergyHUD::RefreshSynergyHUD(float GarrettTrust, float SerafinaTrust, bool bSyncActive)
{
	GarrettTrustPercent = GarrettTrust;
	SerafinaTrustPercent = SerafinaTrust;
	bResonanceSyncActive = bSyncActive;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CompanionSynergyHUD: Synergy HUD refreshed — Garrett: %.2f | Serafina: %.2f | Sync: %s"),
		GarrettTrustPercent, SerafinaTrustPercent, bResonanceSyncActive ? TEXT("ACTIVE") : TEXT("INACTIVE"));
}
