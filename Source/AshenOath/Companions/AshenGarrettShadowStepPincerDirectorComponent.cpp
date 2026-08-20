// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettShadowStepPincerDirectorComponent.h"

UAshenGarrettShadowStepPincerDirectorComponent::UAshenGarrettShadowStepPincerDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettShadowStepPincerDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettShadowStepPincerDirectorComponent::DirectShadowStepPincerStrike(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettShadowStepPincerDirectorComponent: Directed Garrett shadow-step pincer strike against %s"), *TargetEnemy->GetName());
	return true;
}
