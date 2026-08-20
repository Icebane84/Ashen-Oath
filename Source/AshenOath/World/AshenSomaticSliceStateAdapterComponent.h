// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSomaticSliceStateAdapterComponent.generated.h"

/**
 * UAshenSomaticSliceStateAdapterComponent
 *
 * Modular Somatic Slice adapter.
 * Consumes FSoulStateVector invalidation pulses to drive eye emissive, vein creep, and posture morphs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticSliceStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticSliceStateAdapterComponent();

	/** Callback when canonical FSoulStateVector invalidates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SomaticSlice")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	/** Returns eye emissive intensity scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SomaticSlice")
	float GetEyeEmissiveIntensity() const { return EyeEmissiveIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|SomaticSlice")
	float EyeEmissiveIntensity = 0.0f;
};
