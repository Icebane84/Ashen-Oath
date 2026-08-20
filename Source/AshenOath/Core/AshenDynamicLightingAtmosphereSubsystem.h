// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDynamicLightingAtmosphereSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAtmosphereLightingModulatedSignature, float, SunlightIntensity, FLinearColor, FogColor);

/**
 * UAshenDynamicLightingAtmosphereSubsystem
 *
 * World Subsystem modulating sun direction, sky light intensity, and fog color based on Regional Corruption.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicLightingAtmosphereSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|LightingAtmosphere")
	void ModulateAtmosphereForCorruption(float ZoneCorruptionPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LightingAtmosphere|Events")
	FOnAtmosphereLightingModulatedSignature OnAtmosphereModulated;
};
