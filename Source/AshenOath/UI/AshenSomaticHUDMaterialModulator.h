// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticHUDMaterialModulator.generated.h"

/**
 * UAshenSomaticHUDMaterialModulator
 * Drives UI material parameters (heartbeat pulse, chromatic aberration, vignette) based on physical exhaustion and mental strain.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticHUDMaterialModulator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSomaticHUDMaterialModulator();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float HeartbeatPulseRate = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float ChromaticAberrationIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void ModulateHUDMaterialParameters(float StaminaPercent, float SanityPercent);
};
