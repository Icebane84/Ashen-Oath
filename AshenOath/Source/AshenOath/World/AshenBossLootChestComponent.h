// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossLootChestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossChestOpenedSignature, float, EmbersAwarded, FName, ItemAwardedID);

/**
 * UAshenBossLootChestComponent
 *
 * Attached to boss victory chests. Manages key validation, Ember currency grants, and rare item drops.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossLootChestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossLootChestComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|LootChest")
	bool OpenChest(AActor* OpeningActor, FName RequiredKeyID = NAME_None);

	UFUNCTION(BlueprintPure, Category = "AshenOath|LootChest")
	bool IsOpened() const { return bIsOpened; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|LootChest")
	float EmberRewardAmount = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|LootChest")
	FName RareItemRewardID = FName("Item_GreywatchPaladinSword");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LootChest|Events")
	FOnBossChestOpenedSignature OnChestOpened;

private:
	bool bIsOpened = false;
};
