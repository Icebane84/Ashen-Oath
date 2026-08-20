// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenDualityTypes.h"
#include "AshenTransformationThresholdManager.generated.h"

/**
 * UAshenTransformationThresholdManager
 * Manager component driving non-linear smoothstep transformation curves (Phase 1: 0.00-0.55, Phase 2: 0.35-1.00).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransformationThresholdManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTransformationThresholdManager();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Duality")
	FOnDualityStateShifted OnDualityStateShifted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Duality")
	EAshenDualityState CurrentDualityState = EAshenDualityState::LightMode;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Duality")
	void EvaluateTransformationCurves(float RawCorruption);
};
