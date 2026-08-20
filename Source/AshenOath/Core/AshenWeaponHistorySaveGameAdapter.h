// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponHistorySaveGameAdapter.generated.h"

/**
 * UAshenWeaponHistorySaveGameAdapter
 * Serializes total lifetime weapon executions and unlocked rune tiers to persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponHistorySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeaponHistorySaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeWeaponHistoryToSave(int32 LifetimeExecutions, int32 UnlockedRuneTiers);
};
