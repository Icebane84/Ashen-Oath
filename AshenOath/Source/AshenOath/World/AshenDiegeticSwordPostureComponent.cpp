// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 491: Ashen Diegetic Sword Posture Component

#include "AshenDiegeticSwordPostureComponent.h"

UAshenDiegeticSwordPostureComponent::UAshenDiegeticSwordPostureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStanceTag = FName(TEXT("Stance.HighGuard"));
	CalculatedParryWindowMultiplier = 1.25f;
}

void UAshenDiegeticSwordPostureComponent::SetPostureStance(FName StanceTag)
{
	if (StanceTag.IsNone()) return;

	CurrentStanceTag = StanceTag;
	CalculatedParryWindowMultiplier = (StanceTag == FName(TEXT("Stance.HighGuard"))) ? 1.25f : 1.0f;

	OnPostureStanceChanged.Broadcast(CurrentStanceTag, CalculatedParryWindowMultiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSwordPostureComponent: SWORD POSTURE STANCE -> '%s' (Parry Multiplier: %.2fx)."),
		*CurrentStanceTag.ToString(), CalculatedParryWindowMultiplier);
}
