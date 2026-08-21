// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenTripartiteResonanceMasterBridge.generated.h"

/**
 * UAshenTripartiteResonanceMasterBridge
 * 
 * Master orchestrator connecting Tripartite combo triggers, DualSense haptics,
 * MetaSounds audio crescendo, and group finisher cinematics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteResonanceMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteResonanceMasterBridge();

	/** Broadcasts combo phase change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Trio")
	void BroadcastComboPhaseChanged(const FTripartiteComboState& State);

	/** Broadcasts finisher execution */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Trio")
	void BroadcastFinisherExecuted(EHarmonizedFinisherTier Tier, float TotalDamage);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Trio")
	FOnTripartiteComboPhaseChanged OnTripartiteComboPhaseChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Trio")
	FOnHarmonizedFinisherExecuted OnHarmonizedFinisherExecuted;
};
