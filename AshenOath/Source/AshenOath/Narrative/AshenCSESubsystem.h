// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSESubsystem.generated.h"

/**
 * UAshenCSESubsystem
 * 
 * Central Cognitive Synchronization Engine (CSE) world subsystem evaluating real-time psychological perspective deltas and party dissonance.
 */
UCLASS()
class ASHENOATH_API UAshenCSESubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCSESubsystem();

	/** Updates the cognitive perspective vectors and solves party dissonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|CSE")
	void UpdateCognitivePerspectives(
		const FCognitiveStateVector& KaelenVector,
		const FCognitiveStateVector& GarrettVector,
		const FCognitiveStateVector& SerafinaVector,
		const FCognitiveStateVector& ObjectiveVector);

	UFUNCTION(BlueprintPure, Category = "Ashen|CSE")
	float GetCurrentDissonanceIndex() const { return CurrentDissonanceIndex; }

	UFUNCTION(BlueprintPure, Category = "Ashen|CSE")
	ECognitiveDissonanceTier GetCurrentDissonanceTier() const { return CurrentDissonanceTier; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|CSE")
	FOnCognitiveDissonanceShifted OnCognitiveDissonanceShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|CSE")
	FOnCompanionAlignmentUpdated OnCompanionAlignmentUpdated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	float CurrentDissonanceIndex = 0.15f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	ECognitiveDissonanceTier CurrentDissonanceTier = ECognitiveDissonanceTier::HarmonicConsensus;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	FCognitiveStateVector CachedKaelen;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	FCognitiveStateVector CachedGarrett;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	FCognitiveStateVector CachedSerafina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE")
	FCognitiveStateVector CachedObjective;
};
