// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 463: Ashen Combat Environmental Impact Subsystem

#include "AshenCombatEnvironmentalImpactSubsystem.h"

void UAshenCombatEnvironmentalImpactSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatEnvironmentalImpactSubsystem: Initialized — Combat Environmental Impact Engine ONLINE."));
}

void UAshenCombatEnvironmentalImpactSubsystem::RegisterHeavyCombatImpact(FVector Location, float Radius, float PoiseDamage)
{
	OnImpactTriggered.Broadcast(Location, Radius, PoiseDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatEnvironmentalImpactSubsystem: HEAVY COMBAT IMPACT REGISTERED — Location (%s), Radius %.0fu, Debris Poise Damage %.0f."),
		*Location.ToString(), Radius, PoiseDamage);
}
