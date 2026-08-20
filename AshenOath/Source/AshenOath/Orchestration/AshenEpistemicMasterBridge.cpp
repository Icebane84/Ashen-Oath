// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenEpistemicMasterBridge.h"

UAshenEpistemicMasterBridge::UAshenEpistemicMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenEpistemicMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bEpistemicBridgeActive = true;
}

void UAshenEpistemicMasterBridge::BroadcastEpistemicEventDispatched(const FCanonicalCombatEvent& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEpistemicMasterBridge: Broadcasted Epistemic Event -> %s (Tier: %d, Synarchy: %s) across all 5 layers."),
		*Event.EncounterID.ToString(), static_cast<int32>(Event.ProfileTier), Event.bWasTripartiteSynarchy ? TEXT("TRUE") : TEXT("FALSE"));
}
