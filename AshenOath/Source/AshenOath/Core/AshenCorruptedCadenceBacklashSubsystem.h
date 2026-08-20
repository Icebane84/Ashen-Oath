// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCorruptedCadenceBacklashSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPsychicBacklashTriggeredSignature, float, BacklashIntensity, FName, DisruptionTag);

/**
 * UAshenCorruptedCadenceBacklashSubsystem
 *
 * World Subsystem tracking dark ability overuse to trigger delayed, unpredictable Psychic Backlash Echoes.
 */
UCLASS()
class ASHENOATH_API UAshenCorruptedCadenceBacklashSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CorruptedCadence")
	void RecordDarkAbilityCast(float CorruptedCadenceCost);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CorruptedCadence|Events")
	FOnPsychicBacklashTriggeredSignature OnPsychicBacklashTriggered;

private:
	float AccumulatedCadenceStrain = 0.0f;
};
