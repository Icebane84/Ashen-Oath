// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticEyeResonanceModulatorComponent.generated.h"

/**
 * UAshenSomaticEyeResonanceModulatorComponent
 *
 * Binds Corruption to Kaelen's eye emissive and Shadow Mark material parameters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticEyeResonanceModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticEyeResonanceModulatorComponent();

	/** Modulates eye emissive parameter based on corruption float (0.0 - 1.0) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void UpdateEyeEmissive(float Corruption);

	/** Returns current eye emissive scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetEyeEmissiveIntensity() const { return EyeEmissiveIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float EyeEmissiveIntensity = 0.0f;
};
