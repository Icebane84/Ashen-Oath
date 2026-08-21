// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossEncounterSubsystem.generated.h"

class UAshenBossPhaseEvaluatorComponent;
class UAshenArenaDestructionCoordinatorComponent;
class UAshenCompanionCrisisResolverComponent;

/**
 * UAshenBossEncounterSubsystem
 * 
 * Central world subsystem coordinating boss encounter phase transitions,
 * Chaos environmental sunder events, and companion crisis windows.
 */
UCLASS()
class ASHENOATH_API UAshenBossEncounterSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenBossEncounterSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Updates boss health and evaluates phase shifts */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Combat")
	EBossEncounterPhase UpdateBossHealth(float HealthPercent);

	/** Sunders an arena pillar, updating geometry hazards */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Combat")
	bool SunderArenaPillar(int32 PillarIndex);

	/** Triggers a companion pinning crisis window */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Combat")
	FCompanionCrisisContext TriggerCompanionCrisis(FName CompanionName, float WindowDurationSeconds);

	/** Resolves the crisis via player intervention */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Combat")
	bool ResolveCompanionCrisis(bool bIntervenedViaTransference);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss|Combat")
	FOnBossPhaseShifted OnBossPhaseShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss|Combat")
	FOnArenaPillarSundered OnArenaPillarSundered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss|Combat")
	FOnCompanionCrisisTriggered OnCompanionCrisisTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss|Combat")
	FOnCompanionCrisisResolved OnCompanionCrisisResolved;

protected:
	UPROPERTY()
	UAshenBossPhaseEvaluatorComponent* PhaseEvaluator;

	UPROPERTY()
	UAshenArenaDestructionCoordinatorComponent* DestructionCoordinator;

	UPROPERTY()
	UAshenCompanionCrisisResolverComponent* CrisisResolver;
};
