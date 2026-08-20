// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenBossIncursionAIDirectorComponent.h"

UAshenBossIncursionAIDirectorComponent::UAshenBossIncursionAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossIncursionAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenBossIncursionAIDirectorComponent::CoordinatePhaseBehaviors(EBossPhaseState CurrentPhase)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionAIDirectorComponent: Coordinating AI behaviors for Boss Phase %d."),
		static_cast<int32>(CurrentPhase));
}
