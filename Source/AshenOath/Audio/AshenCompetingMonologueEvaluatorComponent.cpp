// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenCompetingMonologueEvaluatorComponent.h"

UAshenCompetingMonologueEvaluatorComponent::UAshenCompetingMonologueEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompetingMonologueEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenCompetingMonologueEvaluatorComponent::TriggerCompetingMonologuePair(const FString& ExternalWorldVoice, const FString& InternalControllerVoice)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompetingMonologueEvaluatorComponent: COMPETING MONOLOGUE -> [World]: \"%s\" <---> [DualSense]: \"%s\""),
		*ExternalWorldVoice, *InternalControllerVoice);
}
