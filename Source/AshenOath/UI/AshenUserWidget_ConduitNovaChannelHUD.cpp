// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ConduitNovaChannelHUD.h"

void UAshenUserWidget_ConduitNovaChannelHUD::UpdateChannelHUD(bool bActive, float Progress)
{
	bIsChannelActive = bActive;
	ChannelProgress = FMath::Clamp(Progress, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ConduitNovaChannelHUD: Conduit Nova Channel %s (Progress: %.1f%%)."),
		bIsChannelActive ? TEXT("ACTIVE") : TEXT("INACTIVE"), ChannelProgress * 100.0f);
}
