// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "AshenOath_HurtboxComponent.generated.h"

class UAshenOath_HealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnParriedSignature, AActor*, Attacker);

/**
 * UAshenOath_HurtboxComponent
 * A collision box component that acts as a damage receiver.
 * Intercepts hits from Hitbox components and forwards damage to the owner's Health component.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_HurtboxComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UAshenOath_HurtboxComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Getters & Setters */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Hurtbox")
	int32 GetTeamId() const { return TeamId; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hurtbox")
	void SetTeamId(int32 NewTeamId) { TeamId = NewTeamId; }

	/** Apply damage directly to this hurtbox (called by Hitboxes). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hurtbox")
	float ReceiveDamage(float DamageAmount, float PoiseAmount, AActor* DamageSource = nullptr);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Hurtbox")
	bool bIsParryWindow;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Hurtbox|Events")
	FOnParriedSignature OnParryTriggered;

private:
	void ResetHitstop();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	int32 TeamId;

	UPROPERTY(BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UAshenOath_HealthComponent* HealthComponent;
};
