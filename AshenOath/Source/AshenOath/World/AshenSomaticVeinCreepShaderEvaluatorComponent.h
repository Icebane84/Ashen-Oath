// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticVeinCreepShaderEvaluatorComponent.generated.h"

/**
 * UAshenSomaticVeinCreepShaderEvaluatorComponent
 * Evaluates procedural vein creep intensity (0.0 to 1.0) and emissive shadow glow thresholds across character meshes during Nova execution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticVeinCreepShaderEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSomaticVeinCreepShaderEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	float CalculateVeinCreepScalar(float Corruption, float IntegrationDebt) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	bool IsEmissiveShadowGlowActive(float VeinCreepScalar) const;
};
