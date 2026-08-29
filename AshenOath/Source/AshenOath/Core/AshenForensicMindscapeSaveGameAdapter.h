// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeSaveGameAdapter.generated.h"

/**
 * UAshenForensicMindscapeSaveGameAdapter
 * 
 * Serializes discovered clues count, solved case IDs, and memory reconstruction states into SaveGame archives.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenForensicMindscapeSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeSaveGameAdapter();

	/** Packages forensic mindscape state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageForensicState(int32 DiscoveredCount, int32 SolvedCount, float LastSynthesisScore);

	/** Restores forensic mindscape state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreForensicState(int32& OutDiscoveredCount, int32& OutSolvedCount, float& OutSynthesisScore);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDiscoveredCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedSolvedCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedSynthesisScore = 0.0f;

private:
	bool bHasSavedData = false;
};
