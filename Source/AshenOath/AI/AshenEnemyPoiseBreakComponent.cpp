// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 453: Ashen Enemy Poise Break Component

#include "AshenEnemyPoiseBreakComponent.h"

UAshenEnemyPoiseBreakComponent::UAshenEnemyPoiseBreakComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxPoise = 100.0f;
	CurrentPoise = 100.0f;
	bIsPoiseBroken = false;
}

float UAshenEnemyPoiseBreakComponent::ApplyPoiseDamage(float PoiseDamageAmount)
{
	if (bIsPoiseBroken) return 0.0f;

	CurrentPoise = FMath::Max(0.0f, CurrentPoise - PoiseDamageAmount);
	if (CurrentPoise <= 0.0f)
	{
		bIsPoiseBroken = true;
		OnPoiseBroken.Broadcast(GetOwner());

		UE_LOG(LogTemp, Error, TEXT("UAshenEnemyPoiseBreakComponent: POISE BROKEN FOR '%s' — EXECUTION WINDOW OPEN!"),
			GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
	}

	return CurrentPoise;
}
