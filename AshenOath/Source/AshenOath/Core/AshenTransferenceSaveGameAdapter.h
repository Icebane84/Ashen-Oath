// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenTransferenceSaveGameAdapter.generated.h"

/**
 * UAshenTransferenceSaveGameAdapter
 * 
 * Serializes and restores Serafina's cumulative burnout and mercy/execution choices.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTransferenceSaveGameAdapter();

	/** Packages transference data for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageTransferenceData(float SerafinaBurnout, int32 MercyCount, int32 ExecutionCount);

	/** Restores transference data from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreTransferenceData(float& OutBurnout, int32& OutMercyCount, int32& OutExecutionCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedBurnout = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedMercyCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedExecutionCount = 0;

private:
	bool bHasSavedData = false;
};
