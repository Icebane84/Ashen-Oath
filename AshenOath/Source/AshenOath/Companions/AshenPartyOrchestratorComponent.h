// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathTrustTypes.h"
#include "AshenPartyOrchestratorComponent.generated.h"

class UAshenCompanionBarkComponent;
class UAshenOath_TrustAccumulationComponent;
class UAshenOath_AlchemicalComponent;
class UAshenOath_WardenComponent;
class UAshenCompanionAIComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyComboTriggeredSignature, FString, ComboName, AActor*, TargetEnemy);

/**
 * UAshenPartyOrchestratorComponent
 *
 * Master orchestrator managing the Trio party dynamics (Kaelen, Garrett, Serafina).
 * Aggregates trust accumulation, alchemical deployment, warden bulwark spells,
 * voice barks, and real-time companion AI into high-level party combat combos.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPartyOrchestratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPartyOrchestratorComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Subsystem Component References ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Party")
	TObjectPtr<UAshenOath_TrustAccumulationComponent> TrustComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Party")
	TObjectPtr<UAshenOath_AlchemicalComponent> AlchemicalComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Party")
	TObjectPtr<UAshenOath_WardenComponent> WardenComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Party")
	TObjectPtr<UAshenCompanionAIComponent> CompanionAIComponent;

	// --- High-Level Trio Combos ---

	/**
	 * Executes "The Sentinel's Bulwark" Combo:
	 * Garrett deploys Smoke Balm to blind the target while Serafina channels Sun Pulse
	 * to grant Kaelen +50% hyper-armor and poise stability.
	 */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Party|Combos")
	bool ExecuteSentinelsBulwarkCombo(AActor* TargetEnemy);

	/**
	 * Executes "Resonant Cleave" Trio Finisher:
	 * Requires Synchronized trust band between Kaelen and companions.
	 * Deals massive 150 damage, breaks posture, and triggers Symbiotic Resonance flow state.
	 */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Party|Combos")
	bool ExecuteResonantCleaveFinisher(AActor* TargetEnemy);

	/** Evaluates whether the Trio qualifies for Synchronized flow state. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Party")
	bool IsTrioSynchronized() const;

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Party|Events")
	FOnPartyComboTriggeredSignature OnPartyComboTriggered;
};
