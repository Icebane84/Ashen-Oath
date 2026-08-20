// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticSaveGameAdapter.generated.h"

/**
 * UAshenSomaticSaveGameAdapter
 * 
 * Serializes and restores the canonical persistent state (FCanonicalSoulStateVector, FCanonicalRelationalMatrix,
 * and uncompiled memory imprint graph edges) to and from the save game archive.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticSaveGameAdapter();

	/** Packages canonical state for save serialization */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSomaticState(
		const FCanonicalSoulStateVector& SoulState,
		const FCanonicalRelationalMatrix& RelationalState,
		const TArray<FMemoryImprintPayload>& UncompiledImprints);

	/** Restores canonical state from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSomaticState(
		FCanonicalSoulStateVector& OutSoulState,
		FCanonicalRelationalMatrix& OutRelationalState,
		TArray<FMemoryImprintPayload>& OutUncompiledImprints);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSerializedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FCanonicalSoulStateVector SavedSoulState;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FCanonicalRelationalMatrix SavedRelationalState;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	TArray<FMemoryImprintPayload> SavedUncompiledImprints;

private:
	bool bHasSerializedData = false;
};
