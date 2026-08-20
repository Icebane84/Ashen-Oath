// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettShadowStepFlankDirectorComponent.h"

UAshenGarrettShadowStepFlankDirectorComponent::UAshenGarrettShadowStepFlankDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettShadowStepFlankDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettShadowStepFlankDirectorComponent::DirectShadowStepFlank(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettShadowStepFlankDirectorComponent: Directed Garrett shadow-step flank strike against %s"), *TargetEnemy->GetName());
	return true;
}
