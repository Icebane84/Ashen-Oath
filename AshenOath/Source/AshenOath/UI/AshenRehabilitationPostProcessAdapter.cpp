// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenRehabilitationPostProcessAdapter.h"

UAshenRehabilitationPostProcessAdapter::UAshenRehabilitationPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRehabilitationPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenRehabilitationPostProcessAdapter::ApplyGoldenRehabilitationBloom(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationPostProcessAdapter: Serene golden bloom set to %s"), bActive ? TEXT("ACTIVE") : TEXT("INACTIVE"));
}
