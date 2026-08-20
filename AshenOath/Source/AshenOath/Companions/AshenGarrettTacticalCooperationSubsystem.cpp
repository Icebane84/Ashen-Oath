// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 706: Ashen Garrett Tactical Cooperation Subsystem

#include "AshenGarrettTacticalCooperationSubsystem.h"

void UAshenGarrettTacticalCooperationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveCooperationLevel = 75.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalCooperationSubsystem: Initialized — Garrett Tactical Cooperation Subsystem ONLINE."));
}

void UAshenGarrettTacticalCooperationSubsystem::ModifyTacticalCooperation(float DeltaCooperation)
{
	ActiveCooperationLevel = FMath::Clamp(ActiveCooperationLevel + DeltaCooperation, 0.0f, 100.0f);
	const float BonusMultiplier = 1.0f + (ActiveCooperationLevel * 0.005f); // Up to +50% synergy bonus

	OnCooperationUpdated.Broadcast(ActiveCooperationLevel, BonusMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTacticalCooperationSubsystem: TACTICAL COOPERATION UPDATED -> Level: %.1f%% | Synergy Bonus: %.2fx."),
		ActiveCooperationLevel, BonusMultiplier);
}
