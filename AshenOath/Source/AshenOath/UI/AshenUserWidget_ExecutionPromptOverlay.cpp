// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ExecutionPromptOverlay.h"

void UAshenUserWidget_ExecutionPromptOverlay::ShowExecutionPrompt(bool bVisible, FString StanceName)
{
	bExecutionPromptVisible = bVisible;
	ActiveStanceIcon = StanceName;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ExecutionPromptOverlay: Execution prompt %s (Stance: %s)"),
		bExecutionPromptVisible ? TEXT("SHOWN") : TEXT("HIDDEN"), *ActiveStanceIcon);
}
