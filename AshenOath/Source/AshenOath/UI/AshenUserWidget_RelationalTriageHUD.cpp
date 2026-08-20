// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_RelationalTriageHUD.h"

void UAshenUserWidget_RelationalTriageHUD::SelectLensOption(EInterpretiveTherapyLens Lens)
{
	SelectedLens = Lens;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_RelationalTriageHUD: Selected Triage Lens Option: %d"),
		static_cast<int32>(SelectedLens));
}
