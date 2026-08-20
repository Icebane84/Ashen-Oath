// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenHallucinationCompanionReactivityAdapter.h"

UAshenHallucinationCompanionReactivityAdapter::UAshenHallucinationCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenHallucinationCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenHallucinationCompanionReactivityAdapter::TriggerCompanionConcernCallout(FName CompanionID, FString IllusionContext)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenHallucinationCompanionReactivityAdapter: %s calls out in concern: 'Kaelen, there is nothing there!' (Context: %s)"),
		*CompanionID.ToString(), *IllusionContext);
}
