// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBladeSaveGameAdapter.generated.h"

/**
 * UAshenParasiticBladeSaveGameAdapter
 * 
 * Serializes Oathbringer's corruption scalar, parasitic bond level, and remaining Gloomwood needle charges.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParasiticBladeSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParasiticBladeSaveGameAdapter();

	/** Packages blade state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageBladeState(float Corruption01, float MassKg, int32 NeedlesRemaining, EBladeParasiteState State);

	/** Restores blade state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreBladeState(float& OutCorruption01, float& OutMassKg, int32& OutNeedlesRemaining, EBladeParasiteState& OutState);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedCorruption01 = 0.15f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedMassKg = 45.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedNeedles = 3;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EBladeParasiteState SavedState = EBladeParasiteState::DormantSteel;

private:
	bool bHasSavedData = false;
};
