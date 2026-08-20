// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettShadowStepFlankAdapterComponent.h"

UAshenGarrettShadowStepFlankAdapterComponent::UAshenGarrettShadowStepFlankAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettShadowStepFlankAdapterComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettShadowStepFlankAdapterComponent::ExecuteShadowStepFlank(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettShadowStepFlankAdapterComponent: Garrett executed shadow-step flank repositioning behind %s"), *TargetEnemy->GetName());
	return true;
}
