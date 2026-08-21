// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossEncounterMasterBridge.generated.h"

/**
 * UAshenBossEncounterMasterBridge
 * 
 * Master orchestrator connecting boss encounter phases, environmental Chaos sundering,
 * companion crisis alerts, and dynamic audio tension.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossEncounterMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossEncounterMasterBridge();

	/** Broadcasts boss phase shift */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Boss")
	void BroadcastPhaseShifted(EBossEncounterPhase NewPhase);

	/** Broadcasts companion crisis alert */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Boss")
	void BroadcastCrisisTriggered(const FCompanionCrisisContext& Context);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Boss")
	FOnBossPhaseShifted OnBossPhaseShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Boss")
	FOnCompanionCrisisTriggered OnCompanionCrisisTriggered;
};
