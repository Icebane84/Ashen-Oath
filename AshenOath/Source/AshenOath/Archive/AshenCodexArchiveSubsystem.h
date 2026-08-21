// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexArchiveSubsystem.generated.h"

/**
 * UAshenCodexArchiveSubsystem
 * 
 * Central world subsystem coordinating player lore unlocking, relic registry,
 * and companion marginalia reflections.
 */
UCLASS()
class ASHENOATH_API UAshenCodexArchiveSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCodexArchiveSubsystem();

	/** Unlocks a codex entry by ID */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Archive")
	bool UnlockCodexEntry(const FName& EntryId, ECodexCategory Category, const FText& Title, const FText& LoreText);

	/** Checks if a codex entry is unlocked */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	bool IsEntryUnlocked(const FName& EntryId) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	int32 GetUnlockedCount() const { return UnlockedEntries.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Archive")
	FOnCodexEntryUnlocked OnCodexEntryUnlocked;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Archive")
	FOnRelicInspected OnRelicInspected;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Archive")
	FOnCompanionMarginaliaAppended OnCompanionMarginaliaAppended;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Archive")
	FOnCodexRepositoryVisibilityChanged OnCodexRepositoryVisibilityChanged;

private:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Archive")
	TMap<FName, FCodexEntry> UnlockedEntries;
};
