// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenShroudKnight.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USoundCue;

/**
 * EShroudKnightState - Defines the operational combat state of the Shroud-Knight boss.
 */
UENUM(BlueprintType)
enum class EShroudKnightState : uint8
{
	Idle            UMETA(DisplayName = "Idle"),
	Stalking        UMETA(DisplayName = "Stalking"),
	SpectralPhasing UMETA(DisplayName = "Spectral Phasing"),
	WarpStriking    UMETA(DisplayName = "Warp Striking"),
	ConsecratedStun UMETA(DisplayName = "Consecrated Stun"),
	PinnedByKaelen  UMETA(DisplayName = "Pinned By Kaelen")
};

/**
 * FCreepingParanoiaEffect - Structure representing active paranoia insanity affliction on a target.
 */
USTRUCT(BlueprintType)
struct FCreepingParanoiaEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	TObjectPtr<AActor> AfflictedActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float CurrentParanoiaLevel = 0.0f; // Range: 0.0f to 1.0f

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float AccumulatedDamageTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float ExpiryTime = 0.0f;
};

/**
 * AAshenShroudKnight
 *
 * Tormented malevolent spirit of Greywatch Outpost's last commander.
 * Merges spectral dither-shading, dynamic stone penetration (wall phasing),
 * and target-blind psychological paranoia infection into a performant UE5 character.
 */
UCLASS()
class ASHENOATH_API AAshenShroudKnight : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenShroudKnight();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// --- Core AI State Machine ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shroud Knight | AI")
	EShroudKnightState CurrentState;

	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | AI")
	void SetAIState(EShroudKnightState NewState);

	// --- Wall Phasing (Stone Penetration) ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Phasing")
	float PhaseCooldown = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Phasing")
	float MaxPhaseDuration = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shroud Knight | Phasing")
	bool bIsPhasing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shroud Knight | Phasing")
	float PhaseDurationTracker;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shroud Knight | Phasing")
	float PhaseCooldownTracker;

	/** Executes transition into wall-phasing state, altering collision profiles */
	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Phasing")
	void InitiatePhaseShift();

	/** Terminate phasing state, verifying no overlap with stone occurs */
	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Phasing")
	void TerminatePhaseShift(bool bForceSolid);

	// --- Warp-Strike Mechanics ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Combat")
	float WarpStrikeDamage = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Combat")
	float WarpStrikeRange = 1200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Combat")
	float WarpStrikeSpeed = 3000.0f;

	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Combat")
	void ExecuteWarpStrike(AActor* TargetActor);

	UFUNCTION()
	void CompleteWarpStrike();

	// --- Creeping Paranoia UI & DoT Infection ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float ParanoiaDoTTickRate = 1.0f; // Seconds between ticks

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float ParanoiaDamagePerTick = 12.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shroud Knight | Paranoia")
	float ParanoiaVignetteMultiplier = 2.5f;

	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Paranoia")
	void ApplyCreepingParanoia(ACharacter* TargetCharacter, float InitialIntensity);

	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Paranoia")
	void UpdateCreepingParanoia(float DeltaTime);

	// --- Trio Confrontation Counters ---
	
	/** Called when Serafina's Consecration Circle (Warden's Light) overlaps with Shroud-Knight */
	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Counter-Tactics")
	void ForceConsecratedAnchor(AActor* ConsecrationSource);

	/** Called when Kaelen parries or delivers a staggered heavy strike to Shroud-Knight */
	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Counter-Tactics")
	void ApplyKaelenPinLock(float Duration);

	/** Called when Garrett triggers a safe zone or lures the Knight into decoy areas */
	UFUNCTION(BlueprintCallable, Category = "Shroud Knight | Counter-Tactics")
	void TriggerGarrettLure(AActor* GarrettActor);

private:
	// --- Material Controls ---
	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> DynMaterials;

	UPROPERTY(Transient)
	TObjectPtr<AActor> ActiveTarget;

	UPROPERTY()
	TArray<FCreepingParanoiaEffect> ActiveParanoiaList;

	FVector WarpStartPos;
	FVector WarpEndPos;
	float WarpAlpha;
	bool bIsWarping;

	// --- Utility Methods ---
	void UpdateMaterialEtherealness(float Alpha);
	bool IsOverlappingStone() const;
	void ApplyDamageToAfflicted(FCreepingParanoiaEffect& Effect, float DeltaTime);
	void ClientUpdateParanoiaPostProcess(ACharacter* Target, float Intensity);

	// Timer handles for stuns and recovery
	FTimerHandle StunRecoveryTimerHandle;
	FTimerHandle PinRecoveryTimerHandle;

	UFUNCTION()
	void RecoverFromConsecratedStun();

	UFUNCTION()
	void RecoverFromKaelenPin();
};
