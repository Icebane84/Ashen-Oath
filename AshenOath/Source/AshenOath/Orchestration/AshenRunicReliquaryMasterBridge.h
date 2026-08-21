// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicReliquaryMasterBridge.generated.h"

/**
 * UAshenRunicReliquaryMasterBridge
 * 
 * Central orchestrator connecting runic socketing, audio chimes, weapon mass evaluation,
 * and HUD updates.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicReliquaryMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicReliquaryMasterBridge();

	/** Broadcasts a completed forge ritual */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Reliquary")
	void BroadcastForgeCompleted(bool bSuccess);

	/** Broadcasts a weapon attunement change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Reliquary")
	void BroadcastWeaponAttunement(const FSoulForgeWeaponState& NewState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Reliquary")
	FOnRunicForgeCompleted OnRunicForgeCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Reliquary")
	FOnWeaponAttunementUpdated OnWeaponAttunementUpdated;
};
