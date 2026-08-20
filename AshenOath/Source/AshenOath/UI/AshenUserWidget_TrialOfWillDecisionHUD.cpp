// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TrialOfWillDecisionHUD.h"

void UAshenUserWidget_TrialOfWillDecisionHUD::SetPromptVisibility(bool bVisible)
{
	bIsPromptVisible = bVisible;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TrialOfWillDecisionHUD: Prompt Visibility: %s"),
		bIsPromptVisible ? TEXT("VISIBLE (0.75s)") : TEXT("HIDDEN"));
}
