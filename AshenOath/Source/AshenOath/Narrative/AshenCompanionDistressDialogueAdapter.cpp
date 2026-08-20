// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCompanionDistressDialogueAdapter.h"

UAshenCompanionDistressDialogueAdapter::UAshenCompanionDistressDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionDistressDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionDistressDialogueAdapter::TriggerCompanionDistressCallout(FName DistressedID, float HealthPercent, float FatigueLevel)
{
	FString Callout = TEXT("I can't hold my footing much longer!");
	if (DistressedID == FName(TEXT("Serafina")))
	{
		Callout = TEXT("Kaelen... the scepter is slipping... my focus is breaking!");
	}
	else if (DistressedID == FName(TEXT("Garrett")))
	{
		Callout = TEXT("Flank's compromised! I'm out of smoke!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionDistressDialogueAdapter: %s: \"%s\" (HP: %.1f%%, Fatigue: %.2f)"),
		*DistressedID.ToString(), *Callout, HealthPercent * 100.0f, FatigueLevel);
}
