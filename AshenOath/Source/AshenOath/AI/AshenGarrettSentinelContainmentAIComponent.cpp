// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenGarrettSentinelContainmentAIComponent.h"

UAshenGarrettSentinelContainmentAIComponent::UAshenGarrettSentinelContainmentAIComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsEscortingSerafina = false;
}
void UAshenGarrettSentinelContainmentAIComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenGarrettSentinelContainmentAIComponent::EvaluateGarrettContainmentTree(bool bIsKaelenUnchained, bool bIsSerafinaChanneling)
{
	if (!bIsKaelenUnchained)
	{
		bIsEscortingSerafina = false;
		return;
	}

	if (bIsSerafinaChanneling)
	{
		bIsEscortingSerafina = true;
		UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettSentinelContainmentAIComponent: ESCORTING SERAFINA! Intercepting monster flanks and blocking Kaelen sweeps!"));
	}
	else
	{
		bIsEscortingSerafina = false;
		UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettSentinelContainmentAIComponent: DEPLOYING GLOOMWOOD DAMPENER NEEDLE ON KAELEN!"));
	}
}
