// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonDestructibleWallComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWallDestroyedSignature, FVector, CrumbleLocation);

/**
 * UAshenDungeonDestructibleWallComponent
 *
 * Attached to cracked dungeon walls. Manages health thresholds and crumble triggers.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonDestructibleWallComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonDestructibleWallComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DestructibleWall")
	void ReceiveStructuralDamage(float DamageAmount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|DestructibleWall")
	bool IsDestroyed() const { return bIsDestroyed; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|DestructibleWall")
	float MaxWallHealth = 250.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DestructibleWall|Events")
	FOnWallDestroyedSignature OnWallDestroyed;

private:
	float CurrentHealth = 250.0f;
	bool bIsDestroyed = false;
};
