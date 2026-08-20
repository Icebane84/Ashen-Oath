// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class ASHENOATH_API AAshenProjectile : public AActor
{
	GENERATED_BODY()

public:
	AAshenProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int32 TeamId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Lifespan;

	/** Activate and launch the projectile */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void Launch(const FVector& StartLocation, const FVector& Direction);

	/** Instantly deactivate, hide, and return projectile to pooled state */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void Deactivate();

private:
	UFUNCTION()
	void OnProjectileOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	FTimerHandle LifespanTimerHandle;
};
