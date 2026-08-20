// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 512: Ashen Campfire Interpretive Lens Menu UMG Widget

#include "AshenUserWidget_CampfireInterpretiveLensMenu.h"

void UAshenUserWidget_CampfireInterpretiveLensMenu::UpdateInterpretiveLensDisplay(FName SelectedLens, float CompiledMetric)
{
	DisplayedLensTag = SelectedLens;
	DisplayedCompiledMetric = CompiledMetric;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CampfireInterpretiveLensMenu: Campfire Interpretive Lens Menu updated — Lens '%s' (Metric: %.2f)."),
		*SelectedLens.ToString(), CompiledMetric);
}
