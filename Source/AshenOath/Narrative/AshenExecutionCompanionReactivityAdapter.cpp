// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenExecutionCompanionReactivityAdapter.h"

UAshenExecutionCompanionReactivityAdapter::UAshenExecutionCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenExecutionCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenExecutionCompanionReactivityAdapter::NotifyCompanionOfExecutionFinisher(FName FoeType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenExecutionCompanionReactivityAdapter: Companion approval imprint (+0.03) generated for executing %s"), *FoeType.ToString());
}
