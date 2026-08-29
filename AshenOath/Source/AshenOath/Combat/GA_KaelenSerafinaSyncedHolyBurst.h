// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenSyncFinisherBalanceDataAsset.h"
#include "GA_KaelenSerafinaSyncedHolyBurst.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSyncedHolyBurstExecutedSignature, float, DamageDealt, float, HealedAmount, float, FatigueAdded);

/**
 * UGA_KaelenSerafinaSyncedHolyBurst
 * Dual-character GAS ability executing a 500 Holy/Phys synchronized blast, healing Kaelen +50 HP,
 * and adding +0.20 Serafina fatigue.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenSerafinaSyncedHolyBurst : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenSerafinaSyncedHolyBurst();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

	/** Direct C++ execution interface */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SyncedHolyBurst")
	bool ExecuteSyncedHolyBurst(AActor* InstigatorActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Balancing")
	UAshenSyncFinisherBalanceDataAsset* BalanceDataAsset;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SyncedHolyBurst|Events")
	FOnSyncedHolyBurstExecutedSignature OnSyncedHolyBurstExecuted;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedHolyBurst")
	float Damage = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedHolyBurst")
	float Radius = 650.0f;
};
