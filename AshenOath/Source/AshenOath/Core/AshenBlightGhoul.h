// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenTraumaMatrixComponent.h"
#include "AshenBlightGhoul.generated.h"

UENUM(BlueprintType)
enum class EBlightGhoulState : uint8
{
	Skittering,     // Default ice-surface rapid movement
	FlockPressing,  // Coordinated horde pressure on a single target
	ClawSwiping,    // Fast melee claw attack
	Recoiling       // Brief post-parry recovery stagger
};

/**
 * AAshenBlightGhoul
 *
 * Fast swarmer enemy from the Frozen Tarn breach encounter.
 * PAA V2.1 Tier I (Pressure): Targets Garrett's crowd control habits.
 * Adversarial Argument: "Preparation is an illusion."
 *
 * Mechanics:
 *   - Fast skittering ice-surface movement (MaxWalkSpeed 600uu)
 *   - Coordinated flocking pressure — bonus damage when 3+ Ghouls target same actor
 *   - Rapid claw swipe attacks (20 damage, 200uu range)
 *   - Recoil stagger (1.5s) when hitting Garrett's tripwire or a consecrated anchor
 *   - UAshenTraumaMatrixComponent pre-configured for Tier I Garrett disruption
 */
UCLASS()
class ASHENOATH_API AAshenBlightGhoul : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenBlightGhoul();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// --- AI State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Ghoul")
	EBlightGhoulState CurrentState;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Ghoul")
	void SetGhoulState(EBlightGhoulState NewState);

	// --- Trauma Matrix (PAA V2.1 Tier I — Garrett Disruption) ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Ghoul")
	TObjectPtr<UAshenTraumaMatrixComponent> TraumaMatrix;

	// --- Combat ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ghoul")
	float ClawDamage = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ghoul")
	float ClawRange = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ghoul")
	float FlockBonusDamageMultiplier = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ghoul")
	int32 FlockThreshold = 3;

	/** Executes rapid claw swipe — 20 base damage, scales with FlockBonusDamageMultiplier if in horde. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Ghoul")
	void ExecuteClawSwipe(AActor* TargetActor, int32 NearbyGhoulCount);

	/** Triggers recoil stagger when hitting a tripwire or consecrated surface. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Ghoul")
	void TriggerRecoilStagger();

private:
	FTimerHandle RecoilTimerHandle;

	UFUNCTION()
	void RecoverFromRecoil();
};
