// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenEarnedKnowledgeGASAbility.generated.h"

/**
 * UAshenEarnedKnowledgeGASAbility
 * Passive combat ability applying permanent frame advantage bonuses (+20% stance stagger, -15% damage taken) against studied monster archetypes.
 */
UCLASS()
class ASHENOATH_API UAshenEarnedKnowledgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenEarnedKnowledgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float StaggerBonusMultiplier = 1.20f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float DefenseBonusMultiplier = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float EvaluateStaggerDamage(float BaseStagger, bool bHasEarnedKnowledge) const;
};
