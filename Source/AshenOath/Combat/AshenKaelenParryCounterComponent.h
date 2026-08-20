// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenKaelenParryCounterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnParryWindowOpenedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnParrySuccessSignature, AActor*, AttackerActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnParryWindowClosedSignature);

/**
 * UAshenKaelenParryCounterComponent
 *
 * Kaelen's precision parry window manager.
 * Opens a 0.25-second parry window on input, detects incoming attacks,
 * and on a successful parry applies a 160-Physical / 70-Poise riposte
 * counter-strike to the attacker. Max 3 consecutive parries per chain
 * before requiring a 1.5-second cool-down.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKaelenParryCounterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKaelenParryCounterComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Parry")
	void OpenParryWindow();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Parry")
	bool TryParryIncomingAttack(AActor* Attacker);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Parry")
	bool IsParryWindowOpen() const { return bParryWindowOpen; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Parry")
	bool IsOnCooldown() const { return bOnCooldown; }

	// --- Configuration ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Parry")
	float ParryWindowDuration = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Parry")
	float CooldownDuration = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Parry")
	int32 MaxConsecutiveParries = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Parry")
	float RiposteDamage = 160.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Parry")
	float RipostePoiseDamage = 70.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Parry|Events")
	FOnParryWindowOpenedSignature OnParryWindowOpened;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Parry|Events")
	FOnParrySuccessSignature OnParrySuccess;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Parry|Events")
	FOnParryWindowClosedSignature OnParryWindowClosed;

private:
	bool bParryWindowOpen = false;
	bool bOnCooldown = false;
	int32 ConsecutiveParryCount = 0;

	FTimerHandle ParryWindowTimer;
	FTimerHandle CooldownTimer;

	void CloseParryWindow();
	void EndCooldown();
};
