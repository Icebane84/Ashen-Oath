// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenNovaExecutionAIDirectorComponent.h"

UAshenNovaExecutionAIDirectorComponent::UAshenNovaExecutionAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNovaExecutionAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenNovaExecutionAIDirectorComponent::EnforceFinisherStaggerState(bool bIsFinisherActive, float StaggerDuration)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNovaExecutionAIDirectorComponent: Finisher Stagger -> Active: %s, Duration: %.1fs"),
		bIsFinisherActive ? TEXT("TRUE") : TEXT("FALSE"), StaggerDuration);
}
