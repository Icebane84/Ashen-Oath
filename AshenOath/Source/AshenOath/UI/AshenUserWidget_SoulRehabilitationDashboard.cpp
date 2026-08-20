// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SoulRehabilitationDashboard.h"

void UAshenUserWidget_SoulRehabilitationDashboard::RefreshDashboard(float Purity, int32 Imprints)
{
	PurityPercentage = Purity;
	RemainingImprints = Imprints;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulRehabilitationDashboard: Dashboard refreshed — Purity: %.1f%% | Imprints: %d"),
		PurityPercentage * 100.0f, RemainingImprints);
}
