// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteCognitiveLoopSubsystem.generated.h"

/**
 * UAshenTripartiteCognitiveLoopSubsystem
 * 
 * Central world subsystem coordinating the tripartite cognitive loop between Kaelen, Garrett, and Serafina across all modes.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteCognitiveLoopSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTripartiteCognitiveLoopSubsystem();

	/** Transitions the tripartite cognitive mode */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tripartite")
	void TransitionMode(ETripartiteBehaviorMode NewMode);

	/** Records synchronized action to increment attunement score */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tripartite")
	void RecordSynchronizedAction(float AttunementDelta);

	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite")
	FTripartiteAttunementVector GetCurrentAttunementVector() const { return CurrentVector; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tripartite")
	FOnTripartiteModeChanged OnTripartiteModeChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tripartite")
	FOnAttunementScoreUpdated OnAttunementScoreUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tripartite")
	FOnEQSSpatialCoordinatesShifted OnEQSSpatialCoordinatesShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tripartite")
	FOnTripartiteFinisherReady OnTripartiteFinisherReady;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Tripartite")
	FTripartiteAttunementVector CurrentVector;
};
