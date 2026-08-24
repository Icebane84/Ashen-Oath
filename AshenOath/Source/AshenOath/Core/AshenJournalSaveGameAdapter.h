// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenJournalSaveGameAdapter.generated.h"

/**
 * UAshenJournalSaveGameAdapter
 * 
 * Serializes unlocked chronicle entries, soot provenance metrics, and deciphered marginalia for SaveGame persistence.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenJournalSaveGameAdapter();

	/** Packages journal codex state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageJournalState(int32 UnlockedCount, float TotalSoot, bool bGarrettUnlocked, bool bSerafinaUnlocked);

	/** Restores journal codex state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreJournalState(int32& OutUnlockedCount, float& OutTotalSoot, bool& OutGarrettUnlocked, bool& OutSerafinaUnlocked);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedUnlockedCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedTotalSoot = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedGarrettUnlocked = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedSerafinaUnlocked = false;

private:
	bool bHasSavedData = false;
};
