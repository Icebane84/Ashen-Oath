// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionSliceStateAdapterComponent.generated.h"

/**
 * UAshenCompanionSliceStateAdapterComponent
 *
 * Modular Companion Slice adapter.
 * Submits relational imprints and consumes FSoulStateVector invalidation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSliceStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSliceStateAdapterComponent();

	/** Submits relational disagreement imprint */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionSlice")
	void SubmitRelationalImprint(FName CompanionID, float FrictionSeverity);

	/** Callback when canonical FSoulStateVector invalidates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionSlice")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	/** Returns Garrett formation distance scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CompanionSlice")
	float GetGarrettFormationDistance() const { return GarrettFormationDistance; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|CompanionSlice")
	float GarrettFormationDistance = 1.0f;
};
