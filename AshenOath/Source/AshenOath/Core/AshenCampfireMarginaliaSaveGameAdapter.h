// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenCampfireMarginaliaSaveGameAdapter.generated.h"

/**
 * UAshenCampfireMarginaliaSaveGameAdapter
 * 
 * Serializes and restores historical campfire marginalia entries and scratch-outs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireMarginaliaSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireMarginaliaSaveGameAdapter();

	/** Packages marginalia history for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageMarginaliaHistory(const TArray<FMarginaliaEntry>& Entries);

	/** Restores marginalia history from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreMarginaliaHistory(TArray<FMarginaliaEntry>& OutEntries);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FMarginaliaEntry> SavedEntries;

private:
	bool bHasSavedData = false;
};
