// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenInnerVoiceSaveGameAdapter.generated.h"

/**
 * UAshenInnerVoiceSaveGameAdapter
 * 
 * Serializes and restores inner voice compilation history and verified memory citations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerVoiceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceSaveGameAdapter();

	/** Packages voice history for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageVoiceHistory(const TArray<FAshenInnerVoicePayload>& History);

	/** Restores voice history from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreVoiceHistory(TArray<FAshenInnerVoicePayload>& OutHistory);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FAshenInnerVoicePayload> SavedVoiceHistory;

private:
	bool bHasData = false;
};
