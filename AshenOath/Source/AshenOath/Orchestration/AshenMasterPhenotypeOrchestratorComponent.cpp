// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenMasterPhenotypeOrchestratorComponent.h"

UAshenMasterPhenotypeOrchestratorComponent::UAshenMasterPhenotypeOrchestratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMasterPhenotypeOrchestratorComponent::DispatchPhenotypeUpdates(const FSoulStateVector& NewState)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenMasterPhenotypeOrchestratorComponent: Dispatching phenotype updates across all attached character components."));
}
