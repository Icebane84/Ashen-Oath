// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenSquadTacticalMasterBridge.generated.h"

/**
 * UAshenSquadTacticalMasterBridge
 * 
 * Master orchestrator connecting tactical command input, UI wheel display,
 * temporal bullet time, and companion GAS activation.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSquadTacticalMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSquadTacticalMasterBridge();

	/** Broadcasts a synchronized co-op combo event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Tactics")
	void BroadcastCoOpCombo(const FTemporalComboExecutionState& ComboState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Tactics")
	FOnCoOpComboTriggered OnCoOpComboTriggered;
};
