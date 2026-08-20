// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeFoliageSwayDissonanceAdapter.generated.h"

/**
 * UAshenGenerativeFoliageSwayDissonanceAdapter
 * Modulates tree and foliage sway speed in response to IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeFoliageSwayDissonanceAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeFoliageSwayDissonanceAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetFoliageSwaySpeedMultiplier() const { return FoliageSwaySpeedMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float FoliageSwaySpeedMultiplier = 1.0f;
};
