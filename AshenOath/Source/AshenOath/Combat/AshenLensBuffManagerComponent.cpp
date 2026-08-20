// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenLensBuffManagerComponent.h"

UAshenLensBuffManagerComponent::UAshenLensBuffManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ThreatPerceptionModifier = 0.0f;
	PoiseBonus = 0.0f;
}
void UAshenLensBuffManagerComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenLensBuffManagerComponent::ApplyLensGameplayBuffs(EInterpretiveLens Lens)
{
	switch (Lens)
	{
	case EInterpretiveLens::Accountability:
		PoiseBonus = 25.0f;
		ThreatPerceptionModifier = 0.0f;
		break;
	case EInterpretiveLens::Grace:
		PoiseBonus = 10.0f;
		ThreatPerceptionModifier = 0.0f;
		break;
	case EInterpretiveLens::Utility:
		PoiseBonus = 0.0f;
		ThreatPerceptionModifier = 0.30f; // +0.3 Threat score boost for 60s
		break;
	default:
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenLensBuffManagerComponent: Applied Lens Buffs -> Poise: +%.1f, ThreatPerception: +%.2f"),
		PoiseBonus, ThreatPerceptionModifier);
}
