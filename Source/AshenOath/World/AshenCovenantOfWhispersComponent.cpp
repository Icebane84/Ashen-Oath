// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 341: Ashen Covenant Of Whispers Component

#include "AshenCovenantOfWhispersComponent.h"

UAshenCovenantOfWhispersComponent::UAshenCovenantOfWhispersComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveCovenants.Empty();
}

void UAshenCovenantOfWhispersComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCovenantOfWhispersComponent::FormCovenantPact(FName PactID, float BoonMultiplier)
{
	if (PactID.IsNone()) return false;

	ActiveCovenants.Add(PactID);
	OnCovenantPactBound.Broadcast(PactID, BoonMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCovenantOfWhispersComponent: COVENANT PACT FORMED — '%s' (Boon Multiplier: %.2fx)."),
		*PactID.ToString(), BoonMultiplier);

	return true;
}

void UAshenCovenantOfWhispersComponent::BreakCovenantPact(FName PactID)
{
	if (ActiveCovenants.Contains(PactID))
	{
		ActiveCovenants.Remove(PactID);
		UE_LOG(LogTemp, Log, TEXT("UAshenCovenantOfWhispersComponent: Covenant pact '%s' dissolved."), *PactID.ToString());
	}
}
