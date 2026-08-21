// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicVFXWeaponAdapterComponent.generated.h"

/**
 * UAshenRunicVFXWeaponAdapterComponent
 * 
 * Modulates weapon mesh emissive intensities and runic glow based on active socket tiers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicVFXWeaponAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicVFXWeaponAdapterComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets the target runic glow emission */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary|VFX")
	void SetRunicGlowTarget(float TargetGlow);

	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary|VFX")
	float GetCurrentGlow() const { return CurrentGlow; }

private:
	float CurrentGlow = 0.0f;
	float DesiredGlow = 0.0f;
};
