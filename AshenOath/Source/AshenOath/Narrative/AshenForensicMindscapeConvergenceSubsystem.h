// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeConvergenceSubsystem.generated.h"

/**
 * UAshenForensicMindscapeConvergenceSubsystem
 * 
 * Central world subsystem orchestrating forensic clue discovery, Memory Palace deduction pinboards, contradiction epiphanies, and psychic catharsis rewards.
 */
UCLASS()
class ASHENOATH_API UAshenForensicMindscapeConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeConvergenceSubsystem();

	/** Registers a discovered forensic clue */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Forensic")
	void DiscoverClue(const FForensicClueRecord& Clue);

	/** Pins a clue to an active Memory Palace deduction case */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Forensic")
	float PinClueToCase(FName CaseId, FName ClueId);

	/** Attempts to synthesize and reconstruct the memory */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Forensic")
	FReconstructedMemoryResult SynthesizeCase(FName CaseId);

	/** Checks if a case is solved */
	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic")
	bool IsCaseSolved(FName CaseId) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Forensic")
	int32 GetDiscoveredCluesCount() const { return ClueRegistry.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Forensic")
	FOnForensicClueDiscovered OnForensicClueDiscovered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Forensic")
	FOnMemoryDeductionBoardUpdated OnMemoryDeductionBoardUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Forensic")
	FOnMemoryPalaceCaseSolved OnMemoryPalaceCaseSolved;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Forensic")
	FOnCompanionContradictionExposed OnCompanionContradictionExposed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Forensic")
	TMap<FName, FForensicClueRecord> ClueRegistry;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Forensic")
	TMap<FName, FMemoryPalaceDeductionBoard> ActiveDeductionBoards;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Forensic")
	TMap<FName, FReconstructedMemoryResult> SolvedCases;
};
