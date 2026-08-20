// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossIncursionSubsystem.generated.h"

/**
 * UAshenBossIncursionSubsystem
 * GameInstance Subsystem managing multi-phase boss encounter state machines (Phase 1, 2, 3), cataclysm timers, and arena boundary locks.
 */
UCLASS()
class ASHENOATH_API UAshenBossIncursionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	FBossEncounterPayload ActiveBossEncounter;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void StartBossEncounter(FName BossId, float MaxHP, float MaxPoise);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool EvaluatePhaseTransition(float HealthPercent, EBossPhaseState& OutNewPhase);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void TriggerBossStagger();
};
