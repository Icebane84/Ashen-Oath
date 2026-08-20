// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenIntegrationRitualComponent.h"

UAshenIntegrationRitualComponent::UAshenIntegrationRitualComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenIntegrationRitualComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenIntegrationRitualComponent::PerformSoulIntegrationRitual(float TraumaDebtToClear)
{
	if (OnIntegrationRitualCompleted.IsBound())
	{
		OnIntegrationRitualCompleted.Broadcast(TraumaDebtToClear);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenIntegrationRitualComponent: Soul integration ritual performed! Trauma debt cleared: %.1f"), TraumaDebtToClear);
	return true;
}
