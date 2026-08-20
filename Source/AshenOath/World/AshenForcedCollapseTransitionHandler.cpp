// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenForcedCollapseTransitionHandler.h"

void UAshenForcedCollapseTransitionHandler::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenForcedCollapseTransitionHandler: Forced Collapse Transition Handler initialized."));
}

void UAshenForcedCollapseTransitionHandler::Deinitialize() { Super::Deinitialize(); }

bool UAshenForcedCollapseTransitionHandler::TriggerInvoluntaryForcedCollapse(float DebtLevel)
{
	bCollapseTransitionInProgress = true;
	UE_LOG(LogTemp, Error, TEXT("UAshenForcedCollapseTransitionHandler: INVOLUNTARY FORCED COLLAPSE TRIGGERED at Debt=%f — Auto-selecting lens and initiating Mindscape transition!"), DebtLevel);
	return true;
}
