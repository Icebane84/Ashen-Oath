// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnreliablePerceptionPhenotypeController.generated.h"

/**
 * UAshenUnreliablePerceptionPhenotypeController
 *
 * Enforces Three Layers of Truth: controls timing noise and sensory artifacts in Layer III
 * without modifying Layer I authoritative combat frames.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliablePerceptionPhenotypeController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliablePerceptionPhenotypeController();

	/** Evaluates perception distortion scalar from IntegrationDebt */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void UpdatePerceptionDistortion(float IntegrationDebt);

	/** Returns current perception distortion scalar (0.0 - 1.0) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetPerceptionDistortionScalar() const { return PerceptionDistortionScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float PerceptionDistortionScalar = 0.0f;
};
