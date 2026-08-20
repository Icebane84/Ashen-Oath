// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenImprintPurificationFXAdapter.h"

UAshenImprintPurificationFXAdapter::UAshenImprintPurificationFXAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenImprintPurificationFXAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenImprintPurificationFXAdapter::TriggerImprintEmberDissolve(int32 ImprintIndex)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenImprintPurificationFXAdapter: Ember dissolve VFX triggered for imprint slot %d"), ImprintIndex);
}
