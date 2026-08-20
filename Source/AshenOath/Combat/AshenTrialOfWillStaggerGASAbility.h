// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenTrialOfWillStaggerGASAbility.generated.h"

/**
 * UAshenTrialOfWillStaggerGASAbility
 * Gameplay Ability activated when Kaelen's poise breaks, applying global time dilation (0.05f for 0.75s) to prompt the Trial of Will choice.
 */
UCLASS()
class ASHENOATH_API UAshenTrialOfWillStaggerGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTrialOfWillStaggerGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float StaggerDilationDuration = 0.75f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ActivateTrialOfWillCrisis(AActor* InstigatorHero);
};
