// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenModularSliceStateBridgeSubsystem.generated.h"

/**
 * UAshenModularSliceStateBridgeSubsystem
 *
 * Master World Subsystem routing canonical FSoulStateVector invalidation pulses
 * to Combat, Companion, World, Audio, and Somatic vertical slices.
 */
UCLASS()
class ASHENOATH_API UAshenModularSliceStateBridgeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Dispatches canonical state invalidation pulse to all registered modular slices */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SliceBridge")
	void DispatchStatePulse(const FSoulStateVector& NewState);
};
