// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenAbomination.generated.h"

UENUM(BlueprintType)
enum class EAbhenAbominationState : uint8
{
	Idle,
	Lurching,
	BoneSpurSweeping,
	OverheadCrushing,
	TripwireStumbled
};

/**
 * AAshenAbomination
 *
 * Colossal misshapen line-breaker boss actor featuring petrified bark armor plates,
 * bone spur sweep arcs, overhead ground crushes, and tripwire stumble mechanics.
 */
UCLASS()
class ASHENOATH_API AAshenAbomination : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenAbomination();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// --- AI State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Boss")
	EAbhenAbominationState CurrentState;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Boss")
	void SetBossState(EAbhenAbominationState NewState);

	// --- Combat Mechanics ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Boss")
	float BoneSpurDamage = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Boss")
	float OverheadCrushDamage = 80.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Boss")
	bool bBarkArmorIntact = true;

	/** Executes 3-limb bone spur sweep arc dealing 60 damage and knocking back targets within 450uu. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Boss")
	void ExecuteBoneSpurSweep(AActor* TargetActor);

	/** Executes massive overhead smash dealing 80 damage and shattering ground within 550uu. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Boss")
	void ExecuteOverheadCrush(AActor* TargetActor);

	/** Triggered when stepping on Garrett's alchemical tripwire, collapsing the boss for 4 seconds. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Boss")
	void OnStumbledByTripwire();

	/** Strips petrified bark armor plating, increasing damage taken by +50%. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Boss")
	void StripBarkArmor();

private:
	FTimerHandle StumbleTimerHandle;

	UFUNCTION()
	void RecoverFromStumble();
};
