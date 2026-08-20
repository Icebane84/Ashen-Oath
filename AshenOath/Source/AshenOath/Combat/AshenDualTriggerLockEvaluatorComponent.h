// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenDualTriggerLockEvaluatorComponent.generated.h"

/**
 * UAshenDualTriggerLockEvaluatorComponent
 * Evaluates whether L2 and R2 are held precisely at 50% travel (within 45% - 55% tolerance) against motorized trigger pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualTriggerLockEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualTriggerLockEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Friction")
	float MinTravelTolerance = 0.45f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Friction")
	float MaxTravelTolerance = 0.55f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Friction")
	bool EvaluateTriggerLock(float L2Travel, float R2Travel, float& OutCorruptionSlipDelta);
};
