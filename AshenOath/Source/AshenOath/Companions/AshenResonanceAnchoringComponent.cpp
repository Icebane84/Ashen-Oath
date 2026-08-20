// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenResonanceAnchoringComponent.h"

UAshenResonanceAnchoringComponent::UAshenResonanceAnchoringComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsResonanceActive = false;
	ResonanceDamageBonus = 0.15f;
}
void UAshenResonanceAnchoringComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenResonanceAnchoringComponent::EvaluateResonanceSync(
	float GarrettTrust,
	float SerafinaTrust,
	float GarrettFatigue,
	float SerafinaFatigue,
	float Resolve)
{
	const bool bTrustBalanced = FMath::Abs(SerafinaTrust - GarrettTrust) < 0.15f;
	const bool bFatigueHealthy = (GarrettFatigue < 0.40f) && (SerafinaFatigue < 0.40f);
	const bool bResolveStrong = Resolve > 0.50f;

	bIsResonanceActive = bTrustBalanced && bFatigueHealthy && bResolveStrong;

	if (bIsResonanceActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenResonanceAnchoringComponent: RESONANCE SYNC ACHIEVED! Tripartite emotional alignment active (+15%% damage bonus granted)."));
	}

	return bIsResonanceActive;
}
