// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenDialogueChoiceEvaluator.generated.h"

/**
 * UAshenDialogueChoiceEvaluator
 * Evaluates player lens choices during campfire relational triage dialogues, mathematically recalculating pairwise trust and resulting stances.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDialogueChoiceEvaluator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDialogueChoiceEvaluator();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	FPairwiseTrustVector CurrentTrustVector;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	ECompiledRelationalStance CurrentStance = ECompiledRelationalStance::WeaverStance;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void EvaluateTherapyChoice(EInterpretiveTherapyLens ChosenLens, float& OutBurnoutDecayModifier, float& OutTrustDelta);
};
