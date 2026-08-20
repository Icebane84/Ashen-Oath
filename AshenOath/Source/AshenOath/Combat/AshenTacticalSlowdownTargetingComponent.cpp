// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 383: Ashen Tactical Slowdown Targeting Component

#include "AshenTacticalSlowdownTargetingComponent.h"

UAshenTacticalSlowdownTargetingComponent::UAshenTacticalSlowdownTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveLockedBone = NAME_None;
}

void UAshenTacticalSlowdownTargetingComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenTacticalSlowdownTargetingComponent::LockWeakPointTarget(FName BoneName, float CritMultiplier)
{
	if (BoneName.IsNone()) return false;

	ActiveLockedBone = BoneName;
	OnTargetLocked.Broadcast(BoneName, CritMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalSlowdownTargetingComponent: WEAK POINT LOCKED — Bone '%s' (Crit Multiplier: %.2fx)."),
		*BoneName.ToString(), CritMultiplier);

	return true;
}
