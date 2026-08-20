// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNyxBileSeepageEvaluatorComponent.generated.h"

/**
 * UAshenNyxBileSeepageEvaluatorComponent
 * Evaluates non-linear smoothstep thresholds for Nyx's bile spawn rates (0 to 35) and Z-axis gravity drip rates (-450.0 uu/s).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNyxBileSeepageEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNyxBileSeepageEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	float CalculateBileSpawnRate(float CorruptionScalar) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	float GetBileGravityForceZ() const;
};
