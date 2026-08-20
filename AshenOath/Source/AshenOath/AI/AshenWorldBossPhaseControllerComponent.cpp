// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 576: Ashen World Boss Phase Controller Component

#include "AshenWorldBossPhaseControllerComponent.h"

UAshenWorldBossPhaseControllerComponent::UAshenWorldBossPhaseControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentPhaseIndex = 1;
	ActiveEnrageMultiplier = 1.0f;
}

void UAshenWorldBossPhaseControllerComponent::AdvanceBossPhase(int32 NextPhaseIndex, float EnrageMultiplier)
{
	CurrentPhaseIndex = NextPhaseIndex;
	ActiveEnrageMultiplier = EnrageMultiplier;

	OnBossPhaseTransitioned.Broadcast(CurrentPhaseIndex, ActiveEnrageMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWorldBossPhaseControllerComponent: BOSS PHASE ADVANCED -> Phase %d | Enrage Multiplier: %.2fx."),
		CurrentPhaseIndex, ActiveEnrageMultiplier);
}
