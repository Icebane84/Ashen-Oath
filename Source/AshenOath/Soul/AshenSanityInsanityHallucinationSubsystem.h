// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSanityInsanityHallucinationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInsanityHallucinationTriggeredSignature, FName, HallucinationID, FVector, Location);

/**
 * UAshenSanityInsanityHallucinationSubsystem
 *
 * World Subsystem spawning transient phantom visual geometry and localized whisper sound triggers when player Sanity is <30%.
 */
UCLASS()
class ASHENOATH_API UAshenSanityInsanityHallucinationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Insanity")
	void EvaluateInsanityHallucination(float CurrentSanity, float MaxSanity, FVector PlayerLocation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Insanity")
	float HallucinationSanityThreshold = 30.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Insanity|Events")
	FOnInsanityHallucinationTriggeredSignature OnHallucinationTriggered;

private:
	bool bHallucinationActive = false;
};
