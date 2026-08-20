// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 693: Ashen Combat Psychological Feed Broadcaster

#include "AshenCombatPsychologicalFeedBroadcaster.h"

void UAshenCombatPsychologicalFeedBroadcaster::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalFeedBroadcastsSent = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatPsychologicalFeedBroadcaster: Initialized — Combat Psychological Feed Broadcaster ONLINE."));
}

void UAshenCombatPsychologicalFeedBroadcaster::BroadcastCombatPsychologicalState(FName StanceTag, FName WillpowerTag, float TrustLevel)
{
	TotalFeedBroadcastsSent++;
	OnCombatFeedBroadcasted.Broadcast(StanceTag, WillpowerTag, TrustLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatPsychologicalFeedBroadcaster: COMBAT FEED BROADCAST SENT -> Stance: '%s' | Willpower: '%s' | Trust: %.1f%% (Total: %d)."),
		*StanceTag.ToString(), *WillpowerTag.ToString(), TrustLevel, TotalFeedBroadcastsSent);
}
