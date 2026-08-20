// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathBurnStaminaDrainComponent.h"

UAshenOathBurnStaminaDrainComponent::UAshenOathBurnStaminaDrainComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}
void UAshenOathBurnStaminaDrainComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenOathBurnStaminaDrainComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bOathBurnActive)
	{
		// Drains stamina at -2.0/s continuously
		UE_LOG(LogTemp, Verbose, TEXT("UAshenOathBurnStaminaDrainComponent: Oath Burn active — Stamina drained by %.2f"), StaminaDrainPerSecond * DeltaTime);
	}
}

void UAshenOathBurnStaminaDrainComponent::SetOathBurnState(bool bActive)
{
	bOathBurnActive = bActive;
	UE_LOG(LogTemp, Warning, TEXT("UAshenOathBurnStaminaDrainComponent: Oath Burn state changed to %s"),
		bOathBurnActive ? TEXT("ACTIVE (-2.0/s Stamina Drain & Recovery Lock)") : TEXT("INACTIVE"));
}
