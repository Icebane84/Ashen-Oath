// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenSerafinaWeavingAIDirectorComponent.h"

UAshenSerafinaWeavingAIDirectorComponent::UAshenSerafinaWeavingAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CriticalPoiseThreshold = 0.25f;
}
void UAshenSerafinaWeavingAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenSerafinaWeavingAIDirectorComponent::EvaluateWeavingPriority(float KaelenPoisePercentage, bool& bShouldDeployAegis)
{
	bShouldDeployAegis = (KaelenPoisePercentage <= CriticalPoiseThreshold);
	if (bShouldDeployAegis)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaWeavingAIDirectorComponent: CRITICAL POISE (%.1f%%) -> Serafina weaving Aegis Net!"),
			KaelenPoisePercentage * 100.0f);
	}
	return bShouldDeployAegis;
}
