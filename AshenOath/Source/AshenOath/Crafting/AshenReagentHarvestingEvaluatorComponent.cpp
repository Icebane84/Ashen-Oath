// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Crafting/AshenReagentHarvestingEvaluatorComponent.h"

UAshenReagentHarvestingEvaluatorComponent::UAshenReagentHarvestingEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenReagentHarvestingEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

int32 UAshenReagentHarvestingEvaluatorComponent::CalculateReagentYield(EAlchemicalReagent Reagent, bool bIsEliteNode, float PerceptionMultiplier) const
{
	const int32 BaseYield = bIsEliteNode ? 3 : 1;
	const float Multiplier = FMath::Max(1.0f, PerceptionMultiplier);
	const int32 FinalYield = FMath::RoundToInt(BaseYield * Multiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenReagentHarvestingEvaluatorComponent: Harvested %d of reagent %d (Elite: %s, Multiplier: %.2f)"),
		FinalYield, static_cast<int32>(Reagent), bIsEliteNode ? TEXT("YES") : TEXT("NO"), Multiplier);

	return FinalYield;
}
