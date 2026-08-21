// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexSaveGameAdapter.generated.h"

/**
 * UAshenCodexSaveGameAdapter
 * 
 * Serializes and restores unlocked codex lore entries and inspected relic states.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCodexSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCodexSaveGameAdapter();

	/** Packages codex archive state for save file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageCodexState(int32 UnlockedCount, const TArray<FName>& UnlockedIds);

	/** Restores codex archive state from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreCodexState(int32& OutUnlockedCount, TArray<FName>& OutUnlockedIds);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedUnlockedCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FName> SavedUnlockedIds;

private:
	bool bHasSavedData = false;
};
