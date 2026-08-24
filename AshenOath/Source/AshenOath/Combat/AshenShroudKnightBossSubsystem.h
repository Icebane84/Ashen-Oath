// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightBossSubsystem.generated.h"

/**
 * UAshenShroudKnightBossSubsystem
 * 
 * Central world subsystem governing the Shroud-Knight boss fight, phase-shifting transitions, Creeping Paranoia, and Trinity Strike.
 */
UCLASS()
class ASHENOATH_API UAshenShroudKnightBossSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenShroudKnightBossSubsystem();

	/** Applies damage to boss and evaluates phase transition */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss")
	void ApplyBossDamage(float DamageAmount);

	/** Sets phase state (physical solid vs spectral phasing) */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss")
	void SetPhaseState(EShroudKnightPhaseState NewState);

	/** Progresses Trinity Strike combo step */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss")
	void AdvanceTrinityStep(ETrinityStrikeStep Step);

	/** Adjusts Kaelen's Paranoia Infection */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss")
	void AdjustParanoiaInfection(float DeltaInfection);

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss")
	FShroudKnightBossVector GetBossState() const { return BossState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss")
	FOnShroudKnightPhaseChanged OnShroudKnightPhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss")
	FOnParanoiaInfectionChanged OnParanoiaInfectionChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss")
	FOnTrinityStrikeProgressed OnTrinityStrikeProgressed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Boss")
	FOnTrinityStrikeCompleted OnTrinityStrikeCompleted;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Boss")
	FShroudKnightBossVector BossState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float MaxBossHealth = 10000.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Boss")
	float CurrentBossHealth = 10000.0f;
};
