// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSESaveGameAdapter.generated.h"

/**
 * UAshenCSESaveGameAdapter
 * 
 * Serializes party cognitive vectors, active/resolved dissonance contracts, and companion alignment history into SaveGame files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCSESaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCSESaveGameAdapter();

	/** Packages CSE state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageCSEState(float DissonanceIndex, ECognitiveDissonanceTier Tier, int32 ResolvedContractCount);

	/** Restores CSE state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreCSEState(float& OutDissonanceIndex, ECognitiveDissonanceTier& OutTier, int32& OutResolvedContractCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedDissonanceIndex = 0.15f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ECognitiveDissonanceTier SavedTier = ECognitiveDissonanceTier::HarmonicConsensus;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedResolvedCount = 0;

private:
	bool bHasSavedData = false;
};
