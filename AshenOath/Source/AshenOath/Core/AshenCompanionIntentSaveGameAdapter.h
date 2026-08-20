// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenCompanionIntentSaveGameAdapter.generated.h"

/**
 * UAshenCompanionIntentSaveGameAdapter
 * 
 * Serializes and restores historical intent evaluations and trust confidence tiers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionIntentSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionIntentSaveGameAdapter();

	/** Packages intent history for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageIntentHistory(const TArray<FCompanionIntentEvaluationResult>& History);

	/** Restores intent history from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreIntentHistory(TArray<FCompanionIntentEvaluationResult>& OutHistory);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FCompanionIntentEvaluationResult> SavedHistory;

private:
	bool bHasData = false;
};
