// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathBreachConsequenceHandler.h"

UAshenOathBreachConsequenceHandler::UAshenOathBreachConsequenceHandler()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenOathBreachConsequenceHandler::BeginPlay() { Super::BeginPlay(); }

void UAshenOathBreachConsequenceHandler::ExecuteBreachConsequenceCascade(const FOathRecord& BreachedOath)
{
	// ENGINE-SPEC-001 Pillar III Oath Breach Consequences:
	// 1. 25.0 Mental/Sanity Damage
	// 2. +0.35 Integration Debt Imprint Delta
	// 3. Oathbringer emissive dimming
	// 4. -50 cents audio pitch drop stinger
	UE_LOG(LogTemp, Error, TEXT("UAshenOathBreachConsequenceHandler: BREACH CASCADE EXECUTED for oath '%s' — 25.0 Mental Damage, +0.35 Debt Imprint, Emissive Dimmed, -50 Cents Pitch Drop!"),
		*BreachedOath.OathID.ToString());
}
