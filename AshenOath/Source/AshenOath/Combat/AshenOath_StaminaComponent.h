// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_StaminaComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStaminaChangedSignature, float, CurrentStamina, float, MaxStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStaminaDepletedSignature);

/**
 * UAshenOath_StaminaComponent
 * Manages character action economy, stamina consumption, and recovery.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_StaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_StaminaComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Consume stamina. Returns true if successful. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stamina")
	bool ConsumeStamina(float Amount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stamina")
	float GetCurrentStamina() const { return CurrentStamina; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stamina")
	float GetMaxStamina() const { return MaxStamina; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stamina")
	void SetCurrentStamina(float NewStamina);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stamina")
	void SetMaxStamina(float NewMaxStamina);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stamina")
	float GetRegenRate() const { return RegenRate; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stamina")
	void SetRegenRate(float NewRate) { RegenRate = NewRate; }

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stamina|Events")
	FOnStaminaChangedSignature OnStaminaChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stamina|Events")
	FOnStaminaDepletedSignature OnStaminaDepleted;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina Settings", meta = (AllowPrivateAccess = "true"))
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina Settings", meta = (AllowPrivateAccess = "true"))
	float RegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stamina Settings", meta = (AllowPrivateAccess = "true"))
	float RegenPauseTime;

	UPROPERTY(VisibleAnywhere, Category = "Stamina State")
	float CurrentStamina;

	UPROPERTY(VisibleAnywhere, Category = "Stamina State")
	float RegenTimer;
};
