// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCrimsonDischargeEvaluatorComponent.generated.h"

/**
 * UAshenCrimsonDischargeEvaluatorComponent
 * Evaluates high-frequency electrostatic sparks (0 to 250 spawn rate) and curl noise force strength (10 to 450) when unchained (>= 0.70).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCrimsonDischargeEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCrimsonDischargeEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	float CalculateCrimsonSparksSpawnRate(float CorruptionScalar) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	float CalculateCurlNoiseStrength(float CorruptionScalar) const;
};
