// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettPhoenixFlankAdapterComponent.h"

UAshenGarrettPhoenixFlankAdapterComponent::UAshenGarrettPhoenixFlankAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettPhoenixFlankAdapterComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettPhoenixFlankAdapterComponent::ExecutePhoenixFlankStrike(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettPhoenixFlankAdapterComponent: Garrett executed Phoenix flank strike against %s"), *TargetEnemy->GetName());
	return true;
}
