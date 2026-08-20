// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSaveManager.generated.h"

/**
 * UAshenSaveManager
 * GameInstanceSubsystem that handles serialization of player character state and active quest tracking.
 */
UCLASS()
class ASHENOATH_API UAshenSaveManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Serialize and save active player state to local disk */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SaveLoad")
	bool SaveGameData(FString SlotName);

	/** Load and deserialize player state from local disk */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SaveLoad")
	bool LoadGameData(FString SlotName);

	/** Check if save data exists for a slot name */
	UFUNCTION(BlueprintPure, Category = "AshenOath|SaveLoad")
	bool HasSaveData(FString SlotName) const;
};
