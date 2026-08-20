// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenControllerFrictionAIDirectorComponent.h"

UAshenControllerFrictionAIDirectorComponent::UAshenControllerFrictionAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenControllerFrictionAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenControllerFrictionAIDirectorComponent::NotifyStrugglePhaseChanged(EStrugglePhase Phase)
{
	if (Phase == EStrugglePhase::Phase2_MartyrsPivot)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenControllerFrictionAIDirectorComponent: Directing elite overhead crush onto ally -> Prompting Martyr's Intercept!"));
	}
}
