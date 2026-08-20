// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenSilenceSaveGameAdapter.generated.h"

/**
 * UAshenSilenceSaveGameAdapter
 * 
 * Serializes and restores wordless support statistics and boundary refusal logs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSilenceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSilenceSaveGameAdapter();

	/** Packages silence and boundary data for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSilenceData(int32 WordlessActionsCount, int32 BoundaryRefusalsCount);

	/** Restores silence and boundary data from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSilenceData(int32& OutWordlessCount, int32& OutBoundaryCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedWordlessCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedBoundaryCount = 0;

private:
	bool bHasSavedData = false;
};
