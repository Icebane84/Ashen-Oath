// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenRelationalEcologySaveGameAdapter.generated.h"

/**
 * UAshenRelationalEcologySaveGameAdapter
 * 
 * Serializes and restores the active fellowship ecology state:
 * - Repair matrices for Garrett and Serafina
 * - Historical multi-author journal entries
 * - Active rupture state history
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalEcologySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalEcologySaveGameAdapter();

	/** Packages fellowship ecology state for save archiving */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageEcologyState(
		const FAshenRepairMatrix& GarrettMatrix,
		const FAshenRepairMatrix& SerafinaMatrix,
		const TArray<FAshenMultiAuthorMarginEntry>& Entries);

	/** Restores fellowship ecology state from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreEcologyState(
		FAshenRepairMatrix& OutGarrettMatrix,
		FAshenRepairMatrix& OutSerafinaMatrix,
		TArray<FAshenMultiAuthorMarginEntry>& OutEntries);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSerializedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FAshenRepairMatrix SavedGarrettMatrix;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FAshenRepairMatrix SavedSerafinaMatrix;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FAshenMultiAuthorMarginEntry> SavedEntries;

private:
	bool bHasSerializedData = false;
};
