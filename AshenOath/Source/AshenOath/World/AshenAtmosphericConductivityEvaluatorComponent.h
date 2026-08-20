// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenAtmosphericConductivityEvaluatorComponent.generated.h"

/**
 * UAshenAtmosphericConductivityEvaluatorComponent
 * Computes elemental and psychic damage conductances based on active weather state (+20% Resonance in PsychicStorm, +30% Freeze in AshBlizzard).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAtmosphericConductivityEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAtmosphericConductivityEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	float CalculateResonanceMultiplier(EWeatherState Weather) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	float CalculateMovementFrictionMultiplier(EWeatherState Weather) const;
};
