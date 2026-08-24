// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaSomaticsSaveGameAdapter.generated.h"

/**
 * UAshenTraumaSomaticsSaveGameAdapter
 * 
 * Serializes and restores somatic state: Vein Corruption, Blade Soot, and Micro-Nicks.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaSomaticsSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaSomaticsSaveGameAdapter();

	/** Packages somatic telemetry for save file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSomatics(float VeinCorruption, float BladeSoot, int32 MicroNicks, float HeartBPM);

	/** Restores somatic telemetry from save file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSomatics(float& OutVeinCorruption, float& OutBladeSoot, int32& OutMicroNicks, float& OutHeartBPM);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedVeinCorruption = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedBladeSoot = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedMicroNicks = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedHeartBPM = 60.0f;

private:
	bool bHasSavedData = false;
};
