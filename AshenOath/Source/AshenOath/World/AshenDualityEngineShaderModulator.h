// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenDualityTypes.h"
#include "AshenDualityEngineShaderModulator.generated.h"

/**
 * UAshenDualityEngineShaderModulator
 * Material Parameter Collection (MPC) modulator driving real-time 2-phase corruption parameter interpolation for Light ↔ Dark mode swaps.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityEngineShaderModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualityEngineShaderModulator();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Duality Shader")
	float CorruptionAmountScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Duality Shader")
	void UpdateDualityShaderParameters(float CorruptionAmount);
};
