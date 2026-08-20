// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenTrialOfWillEvaluatorComponent.generated.h"

/**
 * UAshenTrialOfWillEvaluatorComponent
 * Evaluates the player's active choice during the 0.75s stagger crisis and applies immediate state vector mutations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrialOfWillEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTrialOfWillEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Meaning")
	ETrialOfWillChoice LastChoice = ETrialOfWillChoice::None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Meaning")
	void EvaluateStaggerChoice(ETrialOfWillChoice Choice, float& OutDebtDelta, float& OutCorruptionDelta, float& OutTrustDelta);
};
