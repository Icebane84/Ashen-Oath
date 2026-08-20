// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenParchmentDynamicMaterialAdapter.generated.h"

class UMaterialInstanceDynamic;

/**
 * UAshenParchmentDynamicMaterialAdapter
 * 
 * Modulates parchment texture masks and typography vertex jitter:
 * - Dynamic Jitter: Sin(Time * 20.0) * JitterIntensity
 * - Ink Bleed: Scales with low Resolve / high IntegrationDebt
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParchmentDynamicMaterialAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParchmentDynamicMaterialAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates material shader scalars */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Parchment")
	void UpdateParchmentShader(float IntegrationDebt, float Corruption);

	/** Computes current frame vertex jitter offset */
	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Parchment")
	float CalculateVertexJitterOffset(float TimeSeconds) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Parchment")
	float GetCurrentJitterIntensity() const { return CurrentJitterIntensity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Parchment")
	float MaxJitterIntensity = 0.15f;

private:
	float CurrentJitterIntensity = 0.0f;
	float CurrentInkBleed = 0.0f;
};
