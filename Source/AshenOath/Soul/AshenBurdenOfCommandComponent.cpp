// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 591: Ashen Burden Of Command Component

#include "AshenBurdenOfCommandComponent.h"

UAshenBurdenOfCommandComponent::UAshenBurdenOfCommandComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveBurdenScore = 0.0f;
	CalculatedPartyResolveMultiplier = 1.0f;
}

void UAshenBurdenOfCommandComponent::EvaluateBurdenOfCommand(float LeadershipWeight)
{
	ActiveBurdenScore = FMath::Clamp(LeadershipWeight, 0.0f, 100.0f);
	CalculatedPartyResolveMultiplier = 1.0f + (ActiveBurdenScore / 200.0f);

	OnBurdenEvaluated.Broadcast(ActiveBurdenScore, CalculatedPartyResolveMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBurdenOfCommandComponent: BURDEN OF COMMAND EVALUATED -> Burden Score: %.1f | Party Resolve Multiplier: %.2fx."),
		ActiveBurdenScore, CalculatedPartyResolveMultiplier);
}

void UAshenBurdenOfCommandComponent::AccrueCommandStrain(float Strain)
{
	EvaluateBurdenOfCommand(ActiveBurdenScore + Strain);
}

void UAshenBurdenOfCommandComponent::RestAndRelieveStrain(float Amount)
{
	EvaluateBurdenOfCommand(ActiveBurdenScore - Amount);
}
