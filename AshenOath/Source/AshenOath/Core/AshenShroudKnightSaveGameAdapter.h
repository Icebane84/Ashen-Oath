// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightSaveGameAdapter.generated.h"

/**
 * UAshenShroudKnightSaveGameAdapter
 * 
 * Serializes Shroud-Knight boss defeat metrics, Trinity Strike high score, and paranoia resistance logs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShroudKnightSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShroudKnightSaveGameAdapter();

	/** Packages encounter metrics for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageBossMetrics(bool bDefeated, float FinalHealthPercent, float MaxParanoiaReached, int32 TrinityStrikesLanded);

	/** Restores encounter metrics from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreBossMetrics(bool& OutDefeated, float& OutFinalHealth, float& OutMaxParanoia, int32& OutTrinityStrikes);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedDefeated = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalHealth = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedMaxParanoia = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedTrinityStrikes = 0;

private:
	bool bHasSavedData = false;
};
