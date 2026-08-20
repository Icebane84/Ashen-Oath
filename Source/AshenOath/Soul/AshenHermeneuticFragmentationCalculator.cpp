// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 742: Ashen Hermeneutic Fragmentation Calculator

#include "AshenHermeneuticFragmentationCalculator.h"

float UAshenHermeneuticFragmentationCalculator::CalculateFragmentation(float DissonantNodeCount, float ActiveSpiritualStain)
{
	const float Fragmentation = FMath::Clamp((DissonantNodeCount * 12.0f) + (ActiveSpiritualStain * 0.4f), 0.0f, 100.0f);
	const bool bExceeded = (Fragmentation >= 60.0f);

	OnFragmentationCalculated.Broadcast(Fragmentation, bExceeded);

	UE_LOG(LogTemp, Warning, TEXT("UAshenHermeneuticFragmentationCalculator: FRAGMENTATION CALCULATED -> Nodes: %.0f | Stain: %.1f%% -> Fragmentation: %.1f%% | Threshold Exceeded: %s."),
		DissonantNodeCount, ActiveSpiritualStain, Fragmentation, bExceeded ? TEXT("TRUE") : TEXT("FALSE"));

	return Fragmentation;
}
