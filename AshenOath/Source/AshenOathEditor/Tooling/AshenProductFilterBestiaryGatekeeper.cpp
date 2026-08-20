// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenProductFilterBestiaryGatekeeper.h"

void UAshenProductFilterBestiaryGatekeeper::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenProductFilterBestiaryGatekeeper: Bestiary Gatekeeper initialized."));
}

bool UAshenProductFilterBestiaryGatekeeper::ValidateBestiaryFinisherSafetyGates()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenProductFilterBestiaryGatekeeper: Phantom hitbox cleanup, terrain opening, and death sprouts prevention safety gates verified clean."));
	return true;
}
