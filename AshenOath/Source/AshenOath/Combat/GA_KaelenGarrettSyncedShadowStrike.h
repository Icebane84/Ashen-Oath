// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenSyncFinisherBalanceDataAsset.h"
#include "GA_KaelenGarrettSyncedShadowStrike.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSyncedShadowStrikeExecutedSignature, float, DamageDealt, float, FatigueAdded, int32, TargetsHit);

/**
 * UGA_KaelenGarrettSyncedShadowStrike
 * Dual-character GAS ability executing a 600 Phys/Void shadow assassination with Garrett,
 * scaling by 1.8x against staggered targets and adding +0.25 Garrett fatigue.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGarrettSyncedShadowStrike : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGarrettSyncedShadowStrike();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

	/** Direct C++ execution interface */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SyncedShadowStrike")
	bool ExecuteSyncedShadowStrike(AActor* InstigatorActor, AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Balancing")
	UAshenSyncFinisherBalanceDataAsset* BalanceDataAsset;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SyncedShadowStrike|Events")
	FOnSyncedShadowStrikeExecutedSignature OnSyncedShadowStrikeExecuted;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedShadowStrike")
	float Damage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedShadowStrike")
	float Radius = 500.0f;
};
