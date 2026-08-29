// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceSaveGameAdapter.generated.h"

/**
 * UAshenOathbringerStanceSaveGameAdapter
 * 
 * Serializes active stance preferences, mastery progression points across the 4 guards, and Flow Charge capacity into SaveGame files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerStanceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceSaveGameAdapter();

	/** Packages stance state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageStanceState(EOathbringerMartialStance ActiveStance, float FlowCharge, int32 MasteredStancesCount);

	/** Restores stance state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreStanceState(EOathbringerMartialStance& OutStance, float& OutFlowCharge, int32& OutMasteredCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EOathbringerMartialStance SavedStance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFlowCharge = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedMasteredCount = 0;

private:
	bool bHasSavedData = false;
};
