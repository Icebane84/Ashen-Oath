// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzAudioSaveGameAdapter.generated.h"

/**
 * UAshenQuartzAudioSaveGameAdapter
 * 
 * Serializes dynamic audio preferences, unlocked musical motifs, and combat synchronization high scores.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzAudioSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzAudioSaveGameAdapter();

	/** Packages audio state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageAudioPreferences(float MasterBPM, bool bVocalTracksUnlocked, int32 TotalFlowStatesAchieved);

	/** Restores audio state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreAudioPreferences(float& OutMasterBPM, bool& OutVocalTracksUnlocked, int32& OutTotalFlowStates);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedBPM = 115.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedVocalsUnlocked = true;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTotalFlowStates = 0;

private:
	bool bHasSavedData = false;
};
