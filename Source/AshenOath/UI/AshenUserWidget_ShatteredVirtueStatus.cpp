// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 340: Ashen Shattered Virtue Status UMG Widget

#include "AshenUserWidget_ShatteredVirtueStatus.h"

void UAshenUserWidget_ShatteredVirtueStatus::UpdateVirtueStatusDisplay(FName FractureID, bool bIsActive)
{
	DisplayedFractureID = FractureID;
	bFractureActive = bIsActive;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ShatteredVirtueStatus: Virtue Fracture UI updated — '%s' (Active: %s)."),
		*FractureID.ToString(), bIsActive ? TEXT("TRUE") : TEXT("FALSE"));
}
