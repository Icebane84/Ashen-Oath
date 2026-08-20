// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDiegeticVisualCorruptionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVisualCorruptionUpdatedSignature, float, ChromaticAberrationIntensity, float, LensDistortionAmount);

/**
 * UAshenDiegeticVisualCorruptionSubsystem
 *
 * World Subsystem modulating screen chromatic aberration, eye shaders, and lens distortion based on Soul State Trauma.
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticVisualCorruptionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VisualCorruption")
	void ModulateVisualCorruptionForTrauma(float TraumaLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VisualCorruption|Events")
	FOnVisualCorruptionUpdatedSignature OnVisualCorruptionUpdated;
};
