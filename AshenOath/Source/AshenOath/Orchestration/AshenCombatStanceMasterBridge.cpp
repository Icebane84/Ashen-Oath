// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCombatStanceMasterBridge.h"

UAshenCombatStanceMasterBridge::UAshenCombatStanceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatStanceMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCombatBridgeActive = true;
}

void UAshenCombatStanceMasterBridge::BroadcastStanceChanged(ECombatStance NewStance)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceMasterBridge: Broadcasted Stance Changed Event (Stance: %d)."),
		static_cast<int32>(NewStance));
}

void UAshenCombatStanceMasterBridge::BroadcastFlankExecuted(float FlankDamage, float AngleDegrees)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceMasterBridge: Broadcasted Flank Executed Event (Damage: %.1f, Angle: %.1f deg)."),
		FlankDamage, AngleDegrees);
}
