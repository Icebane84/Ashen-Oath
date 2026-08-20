// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenProjectilePool.generated.h"

class AAshenProjectile;

/**
 * UAshenProjectilePool
 * Actor Component that pre-spawns and recycles projectile actors dynamically
 * using a circular index queue.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenProjectilePool : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenProjectilePool();

protected:
	virtual void BeginPlay() override;

public:
	/** Populate and pre-allocate projectile pool */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ProjectilePool")
	void InitializePool();

	/** Fire/reclaim next projectile from pool */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ProjectilePool")
	void FireProjectile(FVector StartLocation, FVector Direction, APawn* InstigatorPawn, float ProjectileDamage, int32 ProjectileTeamId);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Pool Settings", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AAshenProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Pool Settings", meta = (AllowPrivateAccess = "true"))
	int32 PoolSize;

	UPROPERTY(VisibleAnywhere, Category = "Projectile Pool Cache")
	TArray<AAshenProjectile*> ProjectilePool;

	UPROPERTY(VisibleAnywhere, Category = "Projectile Pool Cache")
	int32 NextIndex;
};
