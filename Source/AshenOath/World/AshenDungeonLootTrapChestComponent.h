// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonLootTrapChestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrapChestSprungSignature, float, Damage, FVector, Location);

/**
 * UAshenDungeonLootTrapChestComponent
 *
 * Trap/mimic chest component emitting a poison explosion cloud when opened without disarming.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonLootTrapChestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonLootTrapChestComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TrapChest")
	bool TriggerChest(AActor* OpeningActor);

	UFUNCTION(BlueprintPure, Category = "AshenOath|TrapChest")
	bool IsSprung() const { return bIsSprung; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TrapChest")
	float TrapExplosionDamage = 180.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TrapChest|Events")
	FOnTrapChestSprungSignature OnTrapChestSprung;

private:
	bool bIsSprung = false;
};
