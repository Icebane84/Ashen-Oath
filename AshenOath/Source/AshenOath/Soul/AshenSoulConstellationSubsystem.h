// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenSoulConstellationSubsystem.generated.h"

/**
 * UAshenSoulConstellationSubsystem
 * ENGINE-SPEC-001 SOVEREIGN KERNEL — UGameInstanceSubsystem holding the canonical FSoulStateVector.
 * Single source of truth. Fires FOnSoulStateVectorInvalidated to wire AnimBP, Shaders, AI, Audio, and Dialogue simultaneously.
 */
UCLASS()
class ASHENOATH_API UAshenSoulConstellationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Fired whenever the compiled state vector changes — all downstream systems subscribe here */
	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Soul Kernel")
	FOnSoulStateVectorInvalidated OnStateVectorInvalidated;

	/** Fired whenever the integration debt stage escalates or de-escalates */
	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Soul Kernel")
	FOnIntegrationDebtStageChanged OnIntegrationDebtStageChanged;

	/** Fired after CompileIdentity() completes successfully */
	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Soul Kernel")
	FOnIdentityCompilationComplete OnIdentityCompilationComplete;

	/** The authoritative canonical soul state vector for game systems */
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul Kernel")
	FSoulStateVector CurrentStateVector;

	/** The detailed kernel identity state vector */
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul Kernel")
	FAshenIdentityStateVector KernelIdentityState;

	/** Pre-existing active behavioral profile cache */
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul Kernel")
	FBehavioralProfile ActiveProfile;

	/** Global Despair level accumulator */
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul Kernel")
	float DespairLevel = 0.0f;

	/**
	 * Core ENGINE-SPEC-001 evaluation function.
	 * Compiles all pending imprint weight deltas into a new BehavioralProfile and DebtStage,
	 * then calls PublishStateVector() to broadcast FOnSoulStateVectorInvalidated to all subscribers.
	 * @param bForcedCollapse — if true, triggers collapse path regardless of debt level
	 */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void CompileIdentity(bool bForcedCollapse = false);

	/** Pre-existing API alias for CompileIdentity() */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void InvokeIntegration(bool bForcedCollapse = false);

	/** Pre-existing API for finalizing lens selection */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void FinalizeIntegration(EInterpretiveLens Lens);

	/** Pre-existing API getter returning the published state vector */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul Kernel")
	FSoulStateVector GetStateVector() const { return CurrentStateVector; }

	/** Pre-existing API getter for active profile */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul Kernel")
	FBehavioralProfile GetActiveProfile() const { return ActiveProfile; }

	/** Pre-existing API getter for despair level */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul Kernel")
	float GetDespairLevel() const { return DespairLevel; }

	/** Apply despair increase on player death */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void ApplyDespairOnDeath(float Amount);

	/** Load saved state from save file */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void LoadSavedState(const FSoulStateVector& SavedVector, float SavedDespair);

	/**
	 * Broadcasts the current FSoulStateVector to all registered downstream systems.
	 * Called automatically at the end of CompileIdentity().
	 */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void PublishStateVector();

	/** Returns the current integration debt stage without recompiling */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	EAshenIntegrationDebtStage GetDebtStage() const;

	/** Apply a raw weight delta from an external imprint — use ImprintBufferComponent for batch ingestion */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul Kernel")
	void ApplyRawWeightDeltas(float StanceDelta, float EmpathicDelta, float TacticalDelta, float DebtDelta);

private:
	void EvaluateBehavioralProfile();
	void EvaluateDebtStage();
	void InvalidateSubsystems();
};
