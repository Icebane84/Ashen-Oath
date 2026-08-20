// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPsychicEchoesLocationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPsychicEchoCreatedSignature, FName, LocationID, float, CorruptionIntensity);

/**
 * UAshenPsychicEchoesLocationSubsystem
 *
 * World Subsystem tracking persistent psychological scars left in world locations by major player choices.
 */
UCLASS()
class ASHENOATH_API UAshenPsychicEchoesLocationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PsychicEchoes")
	void ImprintPsychicEchoAtLocation(FName LocationID, float Intensity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|PsychicEchoes")
	float GetLocationEchoIntensity(FName LocationID) const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PsychicEchoes|Events")
	FOnPsychicEchoCreatedSignature OnPsychicEchoCreated;

private:
	TMap<FName, float> LocationEchoes;
};
