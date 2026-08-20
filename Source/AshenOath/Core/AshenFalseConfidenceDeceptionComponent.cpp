// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 305: Ashen False Confidence Deception Component (UMB-SYS-005)

#include "AshenFalseConfidenceDeceptionComponent.h"

UAshenFalseConfidenceDeceptionComponent::UAshenFalseConfidenceDeceptionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bDeceptionActive = false;
	AttackSpeedMultiplier = 1.0f;
	DeceptionIntensity = 0.0f;
}

void UAshenFalseConfidenceDeceptionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenFalseConfidenceDeceptionComponent::EvaluateFalseConfidenceState(const FAshenSoulStateVector& SoulVector)
{
	if (SoulVector.UnchainedVesselLevel >= 50.0f || SoulVector.IntegrationDebt >= 70.0f)
	{
		bDeceptionActive = true;
		DeceptionIntensity = FMath::Clamp(SoulVector.IntegrationDebt / 100.0f, 0.5f, 1.0f);
		AttackSpeedMultiplier = 1.35f; // Lure: +35% attack speed

		OnDeceptionStateChanged.Broadcast(true, DeceptionIntensity);

		UE_LOG(LogTemp, Warning, TEXT("UAshenFalseConfidenceDeceptionComponent: FALSE CONFIDENCE DECEPTION ACTIVE — Intensity: %.2f (+35%% Speed, Rejection Engaged)."),
			DeceptionIntensity);
	}
	else
	{
		bDeceptionActive = false;
		AttackSpeedMultiplier = 1.0f;
		DeceptionIntensity = 0.0f;

		OnDeceptionStateChanged.Broadcast(false, 0.0f);
	}
}
