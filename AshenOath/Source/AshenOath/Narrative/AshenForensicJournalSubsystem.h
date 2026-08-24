// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenForensicJournalSubsystem.generated.h"

/**
 * UAshenForensicJournalSubsystem
 * 
 * Central world subsystem managing the Forensic Campfire Journal across all 10 scenarios.
 */
UCLASS()
class ASHENOATH_API UAshenForensicJournalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenForensicJournalSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Unlocks or updates a scenario chronicle entry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal")
	void RecordScenarioEntry(
		int32 ScenarioIndex,
		const FString& Title,
		const FText& Summary,
		const FText& KaelenNote,
		const FText& GarrettNote,
		const FText& SerafinaNote,
		float Debt01,
		float SootMicrons);

	/** Retrieves a journal entry by scenario index (1-10) */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal")
	bool GetJournalEntry(int32 ScenarioIndex, FForensicJournalEntry& OutEntry) const;

	/** Gets the total number of unlocked chronicle entries */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal")
	int32 GetUnlockedEntriesCount() const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal")
	FOnJournalEntrySelected OnJournalEntrySelected;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal")
	FOnMarginaliaDeciphered OnMarginaliaDeciphered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal")
	FOnCampfireMoodChanged OnCampfireMoodChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal")
	FOnSootLedgerBurnished OnSootLedgerBurnished;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Journal")
	TMap<int32, FForensicJournalEntry> JournalEntries;
};
