// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenSoulStateVectorDecaySubsystem.generated.h"

/**
 * UAshenSoulStateVectorDecaySubsystem
 * World Subsystem driving temporal decay of imprint weights over session time.
 * Subscribes to OnStateVectorInvalidated and applies exponential decay coefficients to ensure
 * old imprints fade in influence relative to recent psychological events.
 */
UCLASS()
class ASHENOATH_API UAshenSoulStateVectorDecaySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Decay coefficient — multiplied against weight deltas per session hour (default 0.05f per hour) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float DecayCoefficient = 0.05f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void ApplyTemporalDecay(float SessionDeltaHours);
};
