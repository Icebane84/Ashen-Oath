// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenDebtEscalationNarrativeReactivityComponent.h"

UAshenDebtEscalationNarrativeReactivityComponent::UAshenDebtEscalationNarrativeReactivityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDebtEscalationNarrativeReactivityComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDebtEscalationNarrativeReactivityComponent::UpdateNarrativeReactivity(EAshenIntegrationDebtStage Stage)
{
	bPanickedDialogueOptionsUnlocked = (Stage == EAshenIntegrationDebtStage::RuntimeNoise || Stage == EAshenIntegrationDebtStage::ForcedCollapse);
	UE_LOG(LogTemp, Log, TEXT("UAshenDebtEscalationNarrativeReactivityComponent: Narrative reactivity updated — PanickedDialogue=%s"),
		bPanickedDialogueOptionsUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));
}
