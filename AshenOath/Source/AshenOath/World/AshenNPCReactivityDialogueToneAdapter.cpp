// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCReactivityDialogueToneAdapter.h"

UAshenNPCReactivityDialogueToneAdapter::UAshenNPCReactivityDialogueToneAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveToneTag = FName("Tone_Neutral");
}

void UAshenNPCReactivityDialogueToneAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	if (NewState.Corruption >= 0.7f)
	{
		ActiveToneTag = FName("Tone_Terrified");
	}
	else if (NewState.Corruption >= 0.4f)
	{
		ActiveToneTag = FName("Tone_Wary");
	}
	else
	{
		ActiveToneTag = FName("Tone_Welcoming");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenNPCReactivityDialogueToneAdapter: NPC dialogue tone updated to '%s'"), *ActiveToneTag.ToString());
}
