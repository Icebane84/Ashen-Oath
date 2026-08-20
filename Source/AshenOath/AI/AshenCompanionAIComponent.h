// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionAIComponent.generated.h"

/** High-level behavioral state of the Companion AI during combat and unchained containment phases. */
UENUM(BlueprintType)
enum class EAshenCompanionAIState : uint8
{
	OffensiveSupport      UMETA(DisplayName = "Offensive Support"),
	TacticalTriage        UMETA(DisplayName = "Tactical Triage"),
	UnchainedContainment  UMETA(DisplayName = "Unchained Containment"),
	RecoveryAnchoring     UMETA(DisplayName = "Recovery Anchoring")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAshenCompanionAIStateChangedSignature, EAshenCompanionAIState, OldState, EAshenCompanionAIState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshenSymbioticResonanceTriggeredSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshenSymbioticResonanceExpiredSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshenSerafinaCollapsedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshenWardenBulwarkLockedOutSignature);

/** Configuration for Serafina's Empathic Burnout and Transference. */
USTRUCT(BlueprintType)
struct FAshenSerafinaBurnoutConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Burnout")
	float TransferenceCoefficient = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Burnout")
	float CurrentBurnout = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Burnout")
	float LockoutThreshold = 0.70f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Burnout")
	float CollapseThreshold = 1.00f;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Burnout")
	bool bIsLockedOut = false;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Burnout")
	bool bIsCollapsed = false;
};

/** Configuration for Garrett's inventory and tactical interception. */
USTRUCT(BlueprintType)
struct FAshenGarrettInventoryConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Inventory")
	int32 MaxSmokeBalms = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Inventory")
	int32 CurrentSmokeBalms = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tactics")
	float InterceptionRadius = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Tactics")
	float SentinelVigilCooldown = 15.0f;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Tactics")
	float LastVigilTime = -100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Tactics")
	bool bSentinelVigilOnCooldown = false;
};

/**
 * UAshenCompanionAIComponent
 *
 * Real-time tactical companion AI component governing Garrett Alerion and Serafina's support,
 * triage, unchained containment, Sentinel's Vigil intercepts, and Symbiotic Resonance flow states.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionAIComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionAIComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- AI State Machine ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AI")
	EAshenCompanionAIState CurrentAIState;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AI")
	void TransitionToState(EAshenCompanionAIState NewState);

	// --- Symbiotic Resonance Flow State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Resonance")
	bool bSymbioticResonanceActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Resonance")
	float ResonanceDuration = 8.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Resonance")
	float ResonanceTimer = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Resonance")
	void TriggerSymbioticResonance();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Resonance")
	void DeactivateSymbioticResonance();

	// --- Transference & Interception ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Transference")
	void ApplyTransference(float RawDamage, float KaelenCorruption);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Garrett")
	bool DeployGarrettSmokeBalm(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Garrett")
	void CheckSentinelVigilInterception(float DeltaTime);

	// --- Configuration ---
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AshenOath|Config")
	FAshenSerafinaBurnoutConfig SerafinaConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AshenOath|Config")
	FAshenGarrettInventoryConfig GarrettConfig;

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnAshenCompanionAIStateChangedSignature OnStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnAshenSymbioticResonanceTriggeredSignature OnSymbioticResonanceTriggered;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnAshenSymbioticResonanceExpiredSignature OnSymbioticResonanceExpired;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnAshenSerafinaCollapsedSignature OnSerafinaCollapsed;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnAshenWardenBulwarkLockedOutSignature OnWardenBulwarkLockedOut;

private:
	void UpdateAIStateMachine(float DeltaTime);
	void UpdateOffensiveSupport(float DeltaTime);
	void UpdateTacticalTriage(float DeltaTime);
	void UpdateUnchainedContainment(float DeltaTime);
	void UpdateRecoveryAnchoring(float DeltaTime);

	float CalculateNyxMultiplier(float Corruption) const;
	void SetSerafinaLockoutState(bool bLockedOut);
	void TriggerSerafinaCollapse();
	void ExecuteSentinelVigilInterception(AActor* KaelenActor, AActor* SerafinaActor);
};
