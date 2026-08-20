// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenAudioChannelCompanionReactionAdapter.h"

UAshenAudioChannelCompanionReactionAdapter::UAshenAudioChannelCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAudioChannelCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAudioChannelCompanionReactionAdapter::OrientCompanionToPersonalChannel(FName CompanionID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioChannelCompanionReactionAdapter: Companion %s turned head towards Kaelen for Personal Channel Callout."),
		*CompanionID.ToString());
}
