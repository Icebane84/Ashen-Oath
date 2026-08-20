// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenParchmentMarginaliaEvaluatorComponent.h"

UAshenParchmentMarginaliaEvaluatorComponent::UAshenParchmentMarginaliaEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveMarginAnnotation = TEXT("");
}
void UAshenParchmentMarginaliaEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenParchmentMarginaliaEvaluatorComponent::GenerateMarginalia(float TrustScalar, float CorruptionScalar, bool bNearCampfire)
{
	if (CorruptionScalar >= 0.70f)
	{
		ActiveMarginAnnotation = TEXT("Kaelen's Hand: 'The ink won't hold. The ground feels hollow beneath our feet.' (Soot smudged)");
	}
	else if (TrustScalar >= 0.80f)
	{
		ActiveMarginAnnotation = TEXT("Serafina's Hand: 'Golden thread line traced between the watchtowers. We held together.'");
	}
	else
	{
		ActiveMarginAnnotation = TEXT("Garrett's Hand: 'Caltrop supply low. Harvested 4 Ghostbloom roots near the ravine.'");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenParchmentMarginaliaEvaluatorComponent: Generated Marginalia: \"%s\""), *ActiveMarginAnnotation);
}
