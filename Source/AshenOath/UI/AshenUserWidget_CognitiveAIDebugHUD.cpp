// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_CognitiveAIDebugHUD.h"

void UAshenUserWidget_CognitiveAIDebugHUD::RefreshCognitiveAIDebugTelemetry(float Utility, float ReactionProb)
{
	DisplayedUtilityValue = Utility;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CognitiveAIDebugHUD: Refreshed cognitive AI telemetry (Utility: %f, P_react: %f)"), DisplayedUtilityValue, ReactionProb);
}
