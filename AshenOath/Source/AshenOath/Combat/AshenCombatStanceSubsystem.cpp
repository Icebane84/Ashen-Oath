// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenCombatStanceSubsystem.h"

void UAshenCombatStanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveStance = ECombatStance::Flow;
	StanceSwitchCooldown = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceSubsystem: Combat Stance Subsystem initialized (Default: Flow)."));
}
void UAshenCombatStanceSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenCombatStanceSubsystem::SwitchStance(ECombatStance NewStance)
{
	if (ActiveStance == NewStance) return false;

	ActiveStance = NewStance;
	FString StanceName = TEXT("Flow");
	if (ActiveStance == ECombatStance::Aegis) StanceName = TEXT("Aegis");
	else if (ActiveStance == ECombatStance::Berserk) StanceName = TEXT("Berserk");

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatStanceSubsystem: Switched Combat Stance to '%s'!"), *StanceName);
	return true;
}
