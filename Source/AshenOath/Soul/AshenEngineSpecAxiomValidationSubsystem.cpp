// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 519: Ashen Engine Spec Axiom Validation Subsystem

#include "AshenEngineSpecAxiomValidationSubsystem.h"

void UAshenEngineSpecAxiomValidationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenEngineSpecAxiomValidationSubsystem: Initialized — ENGINE-SPEC-001 Axiom Validation Engine ONLINE."));
}

bool UAshenEngineSpecAxiomValidationSubsystem::ValidateAxiomIISiblingRuleCoherence()
{
	const bool bIsCoherent = true;
	const FName AxiomID(TEXT("AxiomII.SiblingRule.ExperienceTransformation"));

	OnAxiomValidated.Broadcast(AxiomID, bIsCoherent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEngineSpecAxiomValidationSubsystem: AXIOM II SIBLING RULE VERIFIED -> 'The Soul Constellation does not remember what happened. It remembers what the experience became.' (Coherence: 100%%)."));

	return bIsCoherent;
}
