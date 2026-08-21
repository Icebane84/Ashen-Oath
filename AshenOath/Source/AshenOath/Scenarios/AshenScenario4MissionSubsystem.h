// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenScenario4MissionSubsystem.generated.h"

/**
 * UAshenScenario4MissionSubsystem
 * 
 * Central world subsystem orchestrating Scenario 4: You Mistake the Wound for the World (Whisperwood).
 */
UCLASS()
class ASHENOATH_API UAshenScenario4MissionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenScenario4MissionSubsystem();

	/** Performs companion grounding check to validate if perceived threat is real */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario4")
	ECompanionGroundingState PerformGroundingCheck(const FCompanionGroundingVerificationContext& Context);

	/** Reduces screen soot layer via touchpad wipe */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario4")
	void WipeSoot(float WipeAmount);

	/** Registers a new cognitive locus in the Memory Palace */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario4")
	void DiscoverCognitiveLocus(const FName& LocusId);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4")
	float GetSootOpacity() const { return MistState.SootLayerOpacity; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4")
	int32 GetDiscoveredLociCount() const { return MistState.UnlockedCognitiveLoci; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario4")
	FOnGroundingCheckExecuted OnGroundingCheckExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario4")
	FOnSootWiped OnSootWiped;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario4")
	FOnCognitiveLocusDiscovered OnCognitiveLocusDiscovered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Scenario4")
	FOnWhisperwoodCleared OnWhisperwoodCleared;

private:
	FWhisperwoodMistState MistState;
};
