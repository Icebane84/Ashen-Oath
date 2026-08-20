// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenReagentHarvestingEvaluatorComponent.generated.h"

/**
 * UAshenReagentHarvestingEvaluatorComponent
 * Evaluates reagent drop chances and harvest yields from blighted world nodes and fallen elite foes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenReagentHarvestingEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenReagentHarvestingEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Harvesting")
	int32 CalculateReagentYield(EAlchemicalReagent Reagent, bool bIsEliteNode, float PerceptionMultiplier) const;
};
