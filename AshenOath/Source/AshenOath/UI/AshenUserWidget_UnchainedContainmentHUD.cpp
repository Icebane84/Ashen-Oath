// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_UnchainedContainmentHUD.h"

void UAshenUserWidget_UnchainedContainmentHUD::UpdateContainmentState(EContainmentState NewState)
{
	ContainmentState = NewState;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_UnchainedContainmentHUD: Containment State Updated -> %d"),
		static_cast<int32>(ContainmentState));
}
