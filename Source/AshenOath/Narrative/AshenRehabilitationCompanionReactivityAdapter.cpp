// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenRehabilitationCompanionReactivityAdapter.h"

UAshenRehabilitationCompanionReactivityAdapter::UAshenRehabilitationCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRehabilitationCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenRehabilitationCompanionReactivityAdapter::TriggerCompanionReflectionForPurity(float IdentityPurityScore)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationCompanionReactivityAdapter: Companion reflection dialogue triggered for purity score %.2f"), IdentityPurityScore);
}
