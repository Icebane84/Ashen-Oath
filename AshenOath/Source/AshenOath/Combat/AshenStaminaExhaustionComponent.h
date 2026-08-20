// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenStaminaExhaustionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExhaustionStateEnteredSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExhaustionStateExitedSignature);

/**
 * UAshenStaminaExhaustionComponent
 *
 * Manages stamina exhaustion daze states triggered when stamina is fully depleted.
 * Applies a 50% movement speed penalty and prevents sprinting until stamina recovers above 25%.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStaminaExhaustionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStaminaExhaustionComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stamina")
	void CheckExhaustionState(float CurrentStamina, float MaxStamina);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stamina")
	bool IsExhausted() const { return bIsExhausted; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Stamina")
	float ExhaustionRecoveryThreshold = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Stamina")
	float MovementSpeedPenalty = 0.5f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stamina|Events")
	FOnExhaustionStateEnteredSignature OnExhaustionEntered;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stamina|Events")
	FOnExhaustionStateExitedSignature OnExhaustionExited;

private:
	bool bIsExhausted = false;
};
