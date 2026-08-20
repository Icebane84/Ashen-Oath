// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenPsychicEchoBossAIComponent.h"

UAshenPsychicEchoBossAIComponent::UAshenPsychicEchoBossAIComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenPsychicEchoBossAIComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenPsychicEchoBossAIComponent::UpdateBossStanceBehavior(uint8 StanceProfileEnum)
{
	AggressionMultiplier = 1.0f + (StanceProfileEnum * 0.25f);
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychicEchoBossAIComponent: Boss AI aggression updated to %.2fx based on player stance profile %d"), AggressionMultiplier, StanceProfileEnum);
}
