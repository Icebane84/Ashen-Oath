// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenTacticalFramePerkEvaluatorComponent.generated.h"

/**
 * UAshenTacticalFramePerkEvaluatorComponent
 * Evaluates unlocked tactical frame perks, providing AI callout advances (-1.0s) and Serafina Sun-Pulse hitbox expansions (+35%).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalFramePerkEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTacticalFramePerkEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float CalculateAdjustedSunPulseRadius(float BaseRadius, bool bHasEarnedKnowledge) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float GetGarrettCalloutTimeAdvance(bool bHasEarnedKnowledge) const;
};
