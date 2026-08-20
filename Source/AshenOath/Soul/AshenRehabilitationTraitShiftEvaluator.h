// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRehabilitationTraitShiftEvaluator.generated.h"

/**
 * UAshenRehabilitationTraitShiftEvaluator
 * Evaluator computing permanent trait stat bonuses (+5% poise, +10% stance recovery) after ritual completion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRehabilitationTraitShiftEvaluator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRehabilitationTraitShiftEvaluator();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float PermanentPoiseBonusMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float StanceRecoveryBonusMultiplier = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void ApplyPermanentRehabilitationTraitBonuses(float IdentityPurityScore);
};
