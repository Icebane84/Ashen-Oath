// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 567: Ashen User Widget Virtue Fracture HUD

#include "AshenUserWidget_VirtueFractureHUD.h"

void UAshenUserWidget_VirtueFractureHUD::UpdateVirtueFractureHUDDisplay(FName VirtueID, float FractureLevelPercent)
{
	ActiveVirtueID = VirtueID;
	ActiveFracturePercent = FMath::Clamp(FractureLevelPercent, 0.0f, 100.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_VirtueFractureHUD: Virtue Fracture Display Updated -> '%s' (Fracture: %.1f%%)."),
		*VirtueID.ToString(), ActiveFracturePercent);
}
