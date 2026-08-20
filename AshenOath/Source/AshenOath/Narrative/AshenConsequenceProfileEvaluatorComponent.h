// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenConsequenceProfileEvaluatorComponent.generated.h"

/**
 * UAshenConsequenceProfileEvaluatorComponent
 * Evaluates whether an encounter resolution warrants Tier I (Common), Tier II (Rare), or Tier III (Milestone Full Convergence).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConsequenceProfileEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenConsequenceProfileEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Epistemic")
	EConsequenceProfileTier EvaluateEncounterTier(bool bIsBossEncounter, bool bIsEliteSymbiote, bool bIsSyncFinisher);
};
