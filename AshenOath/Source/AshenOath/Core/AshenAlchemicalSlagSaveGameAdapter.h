// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagSaveGameAdapter.generated.h"

/**
 * UAshenAlchemicalSlagSaveGameAdapter
 * 
 * Serializes Oathbringer's soot level, active coating, and Garrett's brewed flask inventory across game sessions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalSlagSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagSaveGameAdapter();

	/** Packages alchemical slag state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSlagState(float SootLevel, EAlchemicalBladeCoating Coating, int32 RemainingCharges);

	/** Restores alchemical slag state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSlagState(float& OutSootLevel, EAlchemicalBladeCoating& OutCoating, int32& OutRemainingCharges);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedSootLevel = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EAlchemicalBladeCoating SavedCoating = EAlchemicalBladeCoating::None;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedCharges = 0;

private:
	bool bHasSavedData = false;
};
