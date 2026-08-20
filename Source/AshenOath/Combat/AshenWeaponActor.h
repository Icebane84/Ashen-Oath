// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWeaponActor.generated.h"

class UStaticMeshComponent;
class UAshenOath_HitboxComponent;

UCLASS(Blueprintable, BlueprintType)
class ASHENOATH_API AAshenWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWeaponActor();

protected:
	virtual void BeginPlay() override;

public:
	/** Enable collision on the weapon hitbox */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Weapon")
	void ActivateWeapon();

	/** Disable collision on the weapon hitbox */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Weapon")
	void DeactivateWeapon();

	/** Set the team identifier for damage filtering */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Weapon")
	void SetWeaponTeamId(int32 TeamId);

	/** Getters */
	FORCEINLINE UStaticMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
	FORCEINLINE UAshenOath_HitboxComponent* GetHitbox() const { return HitboxComponent; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* DefaultRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_HitboxComponent* HitboxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats", meta = (AllowPrivateAccess = "true"))
	float BaseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats", meta = (AllowPrivateAccess = "true"))
	float PoiseDamage;
};
