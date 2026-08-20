// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 421: Ashen Cognitive AI Debug Overlay UMG Widget

#include "AshenUserWidget_CognitiveAIDebugOverlay.h"

void UAshenUserWidget_CognitiveAIDebugOverlay::UpdateCognitiveDebugDisplay(FName PrimaryThreatName, float TopUtility, float EntropyDecay)
{
	DisplayedPrimaryThreat = PrimaryThreatName;
	DisplayedUtility = TopUtility;
	DisplayedEntropy = EntropyDecay;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CognitiveAIDebugOverlay: Cognitive AI HUD updated — Threat '%s' (Utility: %.2f, Entropy: %.2fx)."),
		*PrimaryThreatName.ToString(), TopUtility, EntropyDecay);
}
