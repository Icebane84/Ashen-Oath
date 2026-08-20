// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCombatSliceStateAdapterComponent.generated.h"

/**
 * UAshenCombatSliceStateAdapterComponent
 *
 * Modular Combat Slice adapter.
 * Submits combat trauma imprints to ImprintBuffer and consumes FSoulStateVector invalidation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatSliceStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatSliceStateAdapterComponent();

	/** Submits a combat failure imprint (parry break / critical hit) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatSlice")
	void SubmitCombatImprint(float FailureWeight);

	/** Callback when canonical FSoulStateVector invalidates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatSlice")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	/** Returns current stance posture blend weight */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CombatSlice")
	float GetCombatStanceWeight() const { return CombatStanceWeight; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|CombatSlice")
	float CombatStanceWeight = 0.5f;
};
