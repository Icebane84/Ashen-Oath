// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenTripartiteInterpretationComponent.h"

UAshenTripartiteInterpretationComponent::UAshenTripartiteInterpretationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTripartiteInterpretationComponent::BeginPlay() { Super::BeginPlay(); }

FTripartiteInterpretationPackage UAshenTripartiteInterpretationComponent::FormulateInterpretation(FName EncounterID, bool bIsSynarchy)
{
	FTripartiteInterpretationPackage Package;
	if (bIsSynarchy)
	{
		Package.KaelenSubjectiveProse = FString::Printf(TEXT("We struck together at %s. The blade didn't shatter."), *EncounterID.ToString());
		Package.GarrettTacticalNote = TEXT("Dorsal vent exposed after thermal shock. Keep the iron cold.");
		Package.SerafinaGraceLeaf = TEXT("We bore the burden together. The White Flame held.");
	}
	else
	{
		Package.KaelenSubjectiveProse = FString::Printf(TEXT("I severed %s alone. My gauntlet is burned black."), *EncounterID.ToString());
		Package.GarrettTacticalNote = TEXT("Reckless. We almost lost the flank.");
		Package.SerafinaGraceLeaf = TEXT("[Dried tear water stain]");
	}

	return Package;
}
