// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettSmokeScreenPincerDirectorComponent.h"

UAshenGarrettSmokeScreenPincerDirectorComponent::UAshenGarrettSmokeScreenPincerDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettSmokeScreenPincerDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenGarrettSmokeScreenPincerDirectorComponent::DirectSmokeScreenPincer(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettSmokeScreenPincerDirectorComponent: Directed Garrett smoke screen pincer maneuver near %s"), *TargetEnemy->GetName());
	return true;
}
