// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "AshenOath_HitboxComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHitRegisteredSignature, FVector, HitPosition, float, Damage, float, PoiseDamage);

/**
 * UAshenOath_HitboxComponent
 * A collision box component that acts as a damage emitter.
 * Activates for overlaps and applies damage to intersecting Hurtbox components.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_HitboxComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UAshenOath_HitboxComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Getters & Setters */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Hitbox")
	float GetDamage() const { return Damage; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hitbox")
	void SetDamage(float NewDamage) { Damage = FMath::Max(0.0f, NewDamage); }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Hitbox")
	float GetPoiseDamage() const { return PoiseDamage; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hitbox")
	void SetPoiseDamage(float NewPoiseDamage) { PoiseDamage = FMath::Max(0.0f, NewPoiseDamage); }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Hitbox")
	int32 GetTeamId() const { return TeamId; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hitbox")
	void SetTeamId(int32 NewTeamId) { TeamId = NewTeamId; }

	/** Enable collision for a single frame, then disable it to capture immediate overlaps. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hitbox")
	void ActivateOneShot();

public:
	/** Broadcast when a hit is successfully registered on a valid hurtbox */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Hitbox|Events")
	FOnHitRegisteredSignature OnHitRegistered;

protected:
	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float PoiseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	int32 TeamId;
};
