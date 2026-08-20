// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticBreathingRateModulator.generated.h"

/**
 * UAshenSomaticBreathingRateModulator
 *
 * Binds IntegrationDebt and Resolve to diegetic breathing rate audio & mesh morphs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticBreathingRateModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticBreathingRateModulator();

	/** Updates breathing frequency multiplier from debt and resolve */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void UpdateBreathingRate(float Debt, float Resolve);

	/** Returns current breathing rate scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetBreathingRateScalar() const { return BreathingRateScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float BreathingRateScalar = 1.0f;
};
