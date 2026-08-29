// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenOathCharacter.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenCombatCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDevilsBargainCrisisEntered);

class UAshenOath_ImprintBufferComponent;
class UAshenOath_OathRegistryComponent;
class UAshenOath_CurrencyComponent;



/**
 * AAshenCombatCharacter
 * Specialized subclass of the player character.
 * Instantiates and hosts optional combat/horror components to keep the base character lightweight.
 */
UCLASS()
class ASHENOATH_API AAshenCombatCharacter : public AAshenOathCharacter
{
	GENERATED_BODY()

public:
	AAshenCombatCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	/** Called when player health reaches zero -- handles Soulslike death, echo spawning, despair, and Sanctuary respawn. */
	UFUNCTION()
	void HandleCharacterDeath();

public:
	// --- IAshenCharacterInterface Overrides ---
	virtual class UAshenOath_EquipmentComponent* GetEquipmentComponent_Implementation() const override;
	virtual class UAshenOath_StatsComponent* GetStatsComponent_Implementation() const override;
	virtual class UAshenOath_SanityComponent* GetSanityComponent_Implementation() const override;
	virtual class UAshenOath_StaminaComponent* GetStaminaComponent_Implementation() const override;
	virtual class UAshenOath_ManaComponent* GetManaComponent_Implementation() const override;
	virtual class UAshenOath_PoiseComponent* GetPoiseComponent_Implementation() const override;

	virtual class UAshenOath_InputBufferComponent* GetInputBufferComponent() const override;
	virtual float GetCorruptionAmount() const override { return CorruptionAmount; }

	/** Apply hyper-armor, movement speed, and camera overrides for the sundered state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Corruption")
	void ApplyBerserkerState(bool bActive);

	/** Trigger transient hitstop freeze and camera lens FOV warp */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat")
	void TriggerStrikeImpact();

	/** Returns TrioPartySpawnerComponent subobject */
	FORCEINLINE class UAshenTrioPartySpawnerComponent* GetTrioPartySpawnerComponent() const { return TrioPartySpawnerComponent; }

	FORCEINLINE class UAshenDualityStateVectorCompiler* GetDualityStateVectorCompiler() const { return DualityStateVectorCompiler; }
	FORCEINLINE class UAshenDualityShaderShiftComponent* GetDualityShaderShiftComponent() const { return DualityShaderShiftComponent; }
	FORCEINLINE class UAshenDualityEngineShaderModulator* GetDualityEngineShaderModulator() const { return DualityEngineShaderModulator; }
	FORCEINLINE class UAshenDualityMaterialInstanceAdapterComponent* GetDualityMaterialInstanceAdapter() const { return DualityMaterialInstanceAdapter; }
	FORCEINLINE class UAshenDualityPostProcessVolumeAdapter* GetDualityPostProcessAdapter() const { return DualityPostProcessAdapter; }
	FORCEINLINE class UAshenFocusModeInvestigationComponent* GetFocusModeInvestigationComponent() const { return FocusModeInvestigationComponent; }
	FORCEINLINE class UAshenMartyrsTitheComponent* GetMartyrsTitheComponent() const { return MartyrsTitheComponent; }

public:
	/** Toggle the sundered corruption state visually (Light ↔ Dark) */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Corruption")
	void TransitionCorruptionState(bool bBecomeDarkState);

	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Slag")
	void ProcessMeleeHitSootAndCoating(AActor* HitTarget, bool bIsHeavyCleave);

	/** Switch active martial guard stance across the 4 canonical guards */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Stance")
	void SwitchToMartialStance(EOathbringerMartialStance NewStance);

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Stance")
	EOathbringerMartialStance GetCurrentMartialStance() const { return CurrentMartialStance; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Stance")
	const FOathbringerStanceKinematics& GetCurrentStanceKinematics() const { return CurrentStanceKinematics; }

	UFUNCTION()
	void HandleRunicSeamColorUpdated(FLinearColor NewColor, float EmissiveIntensity);

	UFUNCTION()
	void HandleStanceChanged(EOathbringerMartialStance NewStance, const FOathbringerStanceKinematics& Kinematics);

	UFUNCTION()
	void HandleBladeSootLevelChanged(float NewSootLevel, EOathbringerBladeSurfaceState NewSurfaceState);

	UFUNCTION()
	void HandleAlchemicalCoatingApplied(EAlchemicalBladeCoating NewCoating, int32 RemainingCharges);

	UFUNCTION()
	void HandleOathSworn(const FOathRecord& Oath);

	UFUNCTION()
	void HandleOathFulfilled(const FOathRecord& Oath);

	UFUNCTION()
	void HandleOathBroken(const FOathRecord& Oath);

protected:
	void ResetHitStop();

	/**
	 * Called when HealthComponent broadcasts OnHealthChanged.
	 * Fires OnDevilsBargainCrisisEntered once per life when HP drops to or below DevilsBargainHealthThreshold.
	 */
	UFUNCTION()
	void HandleHealthChanged(float CurrentHealth, float MaxHealth);

	UFUNCTION()
	void ResetDevilsBargainTimeDilation();

	UFUNCTION()
	void OnPlayerCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// -----------------------------------------------------------------------
	//  Devil's Bargain Crisis System
	// -----------------------------------------------------------------------

	/**
	 * Fires once per life when HP falls to or below DevilsBargainHealthThreshold.
	 * Bind this in Blueprint to trigger the diegetic crisis prompt, temporal
	 * dilation, and post-process desaturation.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Ashen|DevilsBargain")
	FOnDevilsBargainCrisisEntered OnDevilsBargainCrisisEntered;

	/**
	 * Health percentage (0.0–1.0) at which the Devil's Bargain window opens.
	 * Default: 0.25 (25% HP). Tweak per-encounter in the Editor Details panel.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|DevilsBargain", meta = (ClampMin = "0.01", ClampMax = "0.99"))
	float DevilsBargainHealthThreshold = 0.25f;

	// -----------------------------------------------------------------------
	//  Corruption
	// -----------------------------------------------------------------------

	/** Visual corruption scaling parameter (0.0f = Light, 1.0f = Dark) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Corruption")
	float CorruptionAmount = 0.0f;

	/** Target corruption level to interpolate towards */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Corruption")
	float TargetCorruptionAmount = 0.0f;

	/** Interpolation speed of state transitions */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Corruption")
	float CorruptionTransitionSpeed = 2.0f;

	/** Active Dynamic Material Instances to push parameter state updates */
	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> DynamicMaterials;

	/** Original walk speed cached at BeginPlay */
	float BaseWalkSpeed = 600.0f;

	/** Target camera FOV when in Berserker/Dark mode */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Corruption")
	float BerserkerFOV = 76.0f;



	/** Current interpolated camera FOV */
	float CurrentFOV = 90.0f;

	/** Hitstop global time dilation scale on strike impacts */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat")
	float HitStopDilation = 0.05f;

	/** Timer handle for resetting hitstop time dilation */
	FTimerHandle HitStopTimerHandle;

	/** Ghost-Proof Input Buffer Component */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_InputBufferComponent* InputBufferComponent;

	/** Target Lock-On Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_LockOnComponent* LockOnComponent;

	/** Equipment management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_EquipmentComponent* EquipmentComponent;

	/** Attributes and Progression component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_StatsComponent* StatsComponent;

	/** Sanity management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_SanityComponent* SanityComponent;

	/** Manifestation management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_ManifestationComponent* ManifestationComponent;

	/** Stamina management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_StaminaComponent* StaminaComponent;

	/** Mana management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_ManaComponent* ManaComponent;

	/** Poise management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenOath_PoiseComponent* PoiseComponent;

	/** Sanity Post-Process FX Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenSanityPostProcessComponent* SanityPostProcessComponent;

	/** Psychological Imprint Buffer -- session-volatile pressure accumulator (ENGINE-SPEC-001) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_ImprintBufferComponent* ImprintBufferComponent;

	/** Living Oath Registry Component (ENGINE-SPEC-001 / Pillar III) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_OathRegistryComponent* OathRegistryComponent;

	/** Resource Economy Component -- Embers & Ash (ENGINE-SPEC-001 / Pillar III) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_CurrencyComponent* CurrencyComponent;

	/** Trio Party Spawner Component -- Spawns Serafina & Garrett companions on flanks */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenTrioPartySpawnerComponent* TrioPartySpawnerComponent;

	/** Duality State Vector Compiler (Soul Domain authoritative truth) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDualityStateVectorCompiler* DualityStateVectorCompiler;

	/** Duality Shader Shift Component (World Domain blend ratio driver) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDualityShaderShiftComponent* DualityShaderShiftComponent;

	/** Duality Engine Shader Modulator (World Domain MPC driver) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDualityEngineShaderModulator* DualityEngineShaderModulator;

	/** Duality Material Instance Adapter (World Domain MID updater) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDualityMaterialInstanceAdapterComponent* DualityMaterialInstanceAdapter;

	/** Duality Post Process Volume Adapter (World Domain post-process shifter) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDualityPostProcessVolumeAdapter* DualityPostProcessAdapter;

	/** Active martial stance state and live kinematics */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Combat|Stance")
	EOathbringerMartialStance CurrentMartialStance = EOathbringerMartialStance::VomTag_HighWrath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Combat|Stance")
	FOathbringerStanceKinematics CurrentStanceKinematics;

	/** Focus Mode sensory dilation & investigation component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenFocusModeInvestigationComponent* FocusModeInvestigationComponent;

	/** Martyr's Tithe altruistic max health sacrifice component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenMartyrsTitheComponent* MartyrsTitheComponent;

private:
	/** Guards against firing the crisis delegate more than once per life. Reset in HandleCharacterDeath(). */
	bool bCrisisTriggeredThisLife = false;

	/** Timer handle for resetting Devil's Bargain time dilation in C++ */
	FTimerHandle DevilsBargainTimerHandle;
};


