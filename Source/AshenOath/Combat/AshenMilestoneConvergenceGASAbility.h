// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenMilestoneConvergenceGASAbility.generated.h"

/**
 * UAshenMilestoneConvergenceGASAbility
 * Milestone boss finisher execution ability firing the Tier III full 5-layer convergence pulse.
 */
UCLASS()
class ASHENOATH_API UAshenMilestoneConvergenceGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenMilestoneConvergenceGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float MilestoneFinisherDamage = 2500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool TriggerMilestoneConvergence(AActor* InstigatorActor, FName BossEncounterID);
};
