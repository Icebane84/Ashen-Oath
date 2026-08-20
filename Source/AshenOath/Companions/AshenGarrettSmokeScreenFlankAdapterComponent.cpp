// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettSmokeScreenFlankAdapterComponent.h"

UAshenGarrettSmokeScreenFlankAdapterComponent::UAshenGarrettSmokeScreenFlankAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettSmokeScreenFlankAdapterComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettSmokeScreenFlankAdapterComponent::DeploySmokeScreenFlank(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettSmokeScreenFlankAdapterComponent: Garrett deployed smoke screen flank near %s"), *TargetEnemy->GetName());
	return true;
}
