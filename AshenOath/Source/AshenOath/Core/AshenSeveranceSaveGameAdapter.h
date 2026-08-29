// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceSaveGameAdapter.generated.h"

/**
 * UAshenSeveranceSaveGameAdapter
 * 
 * Serializes execution statistics, decapitation counts, and unlocked executioner passives into SaveGame archives.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeveranceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeveranceSaveGameAdapter();

	/** Packages severance statistics for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSeveranceStats(int32 TotalDecapitations, int32 TotalBisections, float LifetimeAdrenalineGained);

	/** Restores severance statistics from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSeveranceStats(int32& OutDecapitations, int32& OutBisections, float& OutLifetimeAdrenaline);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDecapitations = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedBisections = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedLifetimeAdrenaline = 0.0f;

private:
	bool bHasSavedData = false;
};
