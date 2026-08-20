// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenCampRelationalViewModel.h"

UAshenCampRelationalViewModel::UAshenCampRelationalViewModel()
{
}

void UAshenCampRelationalViewModel::SelectCompanionProfile(FName CompanionName)
{
	SelectedCampCompanion = CompanionName;
	UE_LOG(LogTemp, Log, TEXT("UAshenCampRelationalViewModel: Selected camp companion profile %s"), *SelectedCampCompanion.ToString());
}
