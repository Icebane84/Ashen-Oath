// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubblePhysicsSaveGameAdapter.generated.h"

/**
 * UAshenRubblePhysicsSaveGameAdapter
 * 
 * Serializes persistent rubble clearing, opened tactical passages, and structural collapse milestones into save files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubblePhysicsSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubblePhysicsSaveGameAdapter();

	/** Packages rubble state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageRubbleState(bool bCollapsed, bool bPassageCleared, float RemainingMassKg);

	/** Restores rubble state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreRubbleState(bool& OutCollapsed, bool& OutPassageCleared, float& OutRemainingMass);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedCollapsed = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedPassageCleared = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedRemainingMass = 250.0f;

private:
	bool bHasSavedData = false;
};
