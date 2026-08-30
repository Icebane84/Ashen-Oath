// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenGreatswordStanceFlowComponent.generated.h"

class UAshenStanceFlowBalanceDataAsset;
class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGreatswordStanceChangedSignature, EOathbringerMartialStance, NewStance, FName, TransitionLineName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFlowGlintEvaluatedSignature, EFlowChainingTimingQuality, Quality, float, SpeedBoost, bool, bZeroStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDualSigilResonanceTriggeredSignature, FName, CompanionID, float, Multiplier, float, TrustAwarded);

/**
 * UAshenGreatswordStanceFlowComponent
 *
 * Implements Liechtenauer 4-Guard Martial Kinematics (Vom Tag, Pflug, Ochs, Mordhau),
 * Continuous Kinetic Routing, Dynamic 3-Zone 115 BPM Flow Glint, and Dual-Sigil
 * Companion Pocket Resonance (CONVERGENCE-SPEC-101 / PRS-001 Combat Manifesto V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGreatswordStanceFlowComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGreatswordStanceFlowComponent();

	virtual void BeginPlay() override;

	/** Transitions to a new Liechtenauer martial guard via neutral flick or direct input */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|StanceFlow")
	void TransitionToGuard(EOathbringerMartialStance NewStance);

	/** Executes continuous kinetic routing between cuts, calculating follow-through stamina discounts */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|StanceFlow")
	bool ExecuteKineticAttackRouting(EOathbringerMartialStance TargetStance, float BaseStaminaCost, float& OutFinalStaminaCost);

	/** Opens the 0.15s Flow Glint timing window at the apex of attack recovery */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|StanceFlow")
	void TriggerFlowGlintWindow(float WindowStartTime);

	/** Evaluates 3-zone input timing relative to the 0.15s Flow Glint window */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|StanceFlow")
	EFlowChainingTimingQuality EvaluateFlowGlintInput(float InputTimestamp, float& OutSpeedMultiplier);

	/** Evaluates companion proximity (<= 200uu) and executes Dual-Sigil resonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|StanceFlow")
	bool EvaluateCompanionPocketResonance(AActor* CompanionActor, FName CompanionID);

	// Attributes & Queries
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|StanceFlow")
	EOathbringerMartialStance GetCurrentStance() const { return CurrentStance; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|StanceFlow")
	float GetActivePoiseMultiplier() const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|StanceFlow")
	float GetActiveParryWindow() const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|StanceFlow")
	float GetActiveArmorPenetration() const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|StanceFlow")
	bool IsFlowGlintActive() const { return bIsFlowGlintActive; }

	// Events
	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|StanceFlow|Events")
	FOnGreatswordStanceChangedSignature OnStanceChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|StanceFlow|Events")
	FOnFlowGlintEvaluatedSignature OnFlowGlintEvaluated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|StanceFlow|Events")
	FOnDualSigilResonanceTriggeredSignature OnDualSigilResonanceTriggered;

	// Balance DataAsset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|StanceFlow")
	UAshenStanceFlowBalanceDataAsset* BalanceDataAsset;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|StanceFlow")
	EOathbringerMartialStance CurrentStance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|StanceFlow")
	bool bIsFlowGlintActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|StanceFlow")
	float GlintWindowStartTimestamp = 0.0f;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
