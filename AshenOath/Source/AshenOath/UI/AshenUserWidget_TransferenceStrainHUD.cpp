// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TransferenceStrainHUD.h"

void UAshenUserWidget_TransferenceStrainHUD::UpdateStrainDisplay(ETransferenceStrainStage Stage, bool bDelirium)
{
	DisplayedStrainStage = Stage;
	bIsDeliriumActive = bDelirium;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TransferenceStrainHUD: Strain Stage: %d, Delirium Active: %s"),
		static_cast<int32>(DisplayedStrainStage), bIsDeliriumActive ? TEXT("TRUE") : TEXT("FALSE"));
}
