// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenNovaPostProcessAdapter.h"

UAshenNovaPostProcessAdapter::UAshenNovaPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNovaPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNovaPostProcessAdapter::ApplyNovaPostProcess(float ExecutionProgress, float Isolation, float Resolve)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNovaPostProcessAdapter: Applied Nova Post-Process -> Progress: %.2f, Isolation: %.2f, Resolve: %.2f"),
		ExecutionProgress, Isolation, Resolve);
}
