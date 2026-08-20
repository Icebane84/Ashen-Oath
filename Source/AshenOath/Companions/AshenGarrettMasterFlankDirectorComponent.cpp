// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettMasterFlankDirectorComponent.h"

UAshenGarrettMasterFlankDirectorComponent::UAshenGarrettMasterFlankDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettMasterFlankDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettMasterFlankDirectorComponent::DirectMasterFlankStrike(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettMasterFlankDirectorComponent: Directed Garrett master flank strike against %s"), *TargetEnemy->GetName());
	return true;
}
