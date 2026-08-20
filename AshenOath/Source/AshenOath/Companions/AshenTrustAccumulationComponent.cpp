// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 239: Ashen Trust Accumulation Component

#include "AshenTrustAccumulationComponent.h"

UAshenTrustAccumulationComponent::UAshenTrustAccumulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxTrustScore = 100.0f;
	CompanionTrustMap.Add(FName("Garrett"), 25.0f);
	CompanionTrustMap.Add(FName("Serafina"), 25.0f);
}

void UAshenTrustAccumulationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTrustAccumulationComponent::AddTrust(FName CompanionName, float TrustDelta)
{
	if (CompanionName.IsNone()) return;

	float CurrentScore = GetTrustScore(CompanionName);
	float NewScore = FMath::Clamp(CurrentScore + TrustDelta, 0.0f, MaxTrustScore);

	CompanionTrustMap.FindOrAdd(CompanionName) = NewScore;
	OnTrustChanged.Broadcast(CompanionName, NewScore);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTrustAccumulationComponent: Trust for '%s' updated: %.1f -> %.1f (Max: %.1f)."),
		*CompanionName.ToString(), CurrentScore, NewScore, MaxTrustScore);
}

float UAshenTrustAccumulationComponent::GetTrustScore(FName CompanionName) const
{
	if (const float* FoundScore = CompanionTrustMap.Find(CompanionName))
	{
		return *FoundScore;
	}
	return 0.0f;
}

float UAshenTrustAccumulationComponent::GetSynergyDamageMultiplier(FName CompanionName) const
{
	const float Score = GetTrustScore(CompanionName);
	// 0 trust -> 1.0x, 100 trust -> 1.5x damage multiplier
	return 1.0f + (Score / MaxTrustScore) * 0.50f;
}
