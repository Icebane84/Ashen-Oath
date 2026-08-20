// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRealitySunderingEvaluatorComponent.generated.h"

/**
 * UAshenRealitySunderingEvaluatorComponent
 * Evaluates reality stability index, geometry distortion intensity, and dimensional cleave multipliers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRealitySunderingEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRealitySunderingEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Reality")
	float CalculateGeometryDistortion(float IncursionIntensity, float DistanceToNearestRift, float MaxRiftRadius) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Reality")
	float CalculateSunderingDamageMultiplier(float CurrentDebt) const;
};
