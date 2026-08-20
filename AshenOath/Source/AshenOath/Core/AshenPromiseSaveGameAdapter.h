// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenPromiseSaveGameAdapter.generated.h"

/**
 * UAshenPromiseSaveGameAdapter
 * 
 * Serializes and restores canonical promises and retroactive journal marginalia.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPromiseSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPromiseSaveGameAdapter();

	/** Packages promise and marginalia records for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackagePromiseData(int32 ActiveCount, int32 FulfilledCount, int32 MarginaliaCount);

	/** Restores promise and marginalia records from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestorePromiseData(int32& OutActiveCount, int32& OutFulfilledCount, int32& OutMarginaliaCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedActiveCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedFulfilledCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedMarginaliaCount = 0;

private:
	bool bHasSavedData = false;
};
