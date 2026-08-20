// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TripartiteResourceHUD.h"

void UAshenUserWidget_TripartiteResourceHUD::UpdateResourceState(const FTripartiteResourceState& InState)
{
	DisplayedState = InState;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TripartiteResourceHUD: Corruption: %.2f | Burnout: %.2f | Posture: %.2f"),
		DisplayedState.KaelenCorruption, DisplayedState.SerafinaBurnout, DisplayedState.GarrettSanityPosture);
}
