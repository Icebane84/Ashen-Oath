// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenTrialOfWillAIDirectorComponent.h"

UAshenTrialOfWillAIDirectorComponent::UAshenTrialOfWillAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTrialOfWillAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTrialOfWillAIDirectorComponent::NotifyStaggerChoiceExecuted(ETrialOfWillChoice Choice)
{
	if (Choice == ETrialOfWillChoice::Trust)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillAIDirectorComponent: Companion AI entered 8s Positional Anticipation state!"));
	}
	else if (Choice == ETrialOfWillChoice::Defiance)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenTrialOfWillAIDirectorComponent: Garrett covering peripheral flanks due to Kaelen self-reliance."));
	}
}
