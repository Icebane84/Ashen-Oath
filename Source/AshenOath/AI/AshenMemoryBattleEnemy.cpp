// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenMemoryBattleEnemy.h"

AAshenMemoryBattleEnemy::AAshenMemoryBattleEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMemoryBattleEnemy::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMemoryBattleEnemy: Memory Battle Enemy spawned in Mindscape."));
}

void AAshenMemoryBattleEnemy::ScaleEnemyToImprint(float ImprintWeight)
{
	BaseHealth = 500.0f * (1.0f + (ImprintWeight * ImprintWeightMultiplier));
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryBattleEnemy: Scaled Memory Enemy Health to %.1f based on Imprint Weight %.2f."),
		BaseHealth, ImprintWeight);
}
