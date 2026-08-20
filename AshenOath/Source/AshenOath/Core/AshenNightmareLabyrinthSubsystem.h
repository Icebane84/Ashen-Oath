// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenNightmareLabyrinthSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNightmareTrialCompletedSignature, FName, TrialID, bool, bTrialPassed);

/**
 * UAshenNightmareLabyrinthSubsystem
 *
 * World Subsystem running nightmare psychological trials in Mindscape dungeons to unlock unique skill evolutions.
 */
UCLASS()
class ASHENOATH_API UAshenNightmareLabyrinthSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NightmareLabyrinth")
	bool StartNightmareTrial(FName TrialID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NightmareLabyrinth")
	void CompleteNightmareTrial(FName TrialID, bool bSuccess);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NightmareLabyrinth|Events")
	FOnNightmareTrialCompletedSignature OnNightmareTrialCompleted;

private:
	FName ActiveTrialID;
};
