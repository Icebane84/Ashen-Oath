// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenSyncFinisherBalanceDataAsset.h"
#include "AshenTripartiteSovereignFinisherGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTripartiteZenithExecutedSignature, float, DamageDealt, float, PoiseDamage, float, TimeDilation, float, FatigueAdded);

/**
 * UAshenTripartiteSovereignFinisherGASAbility
 * Grand Zenith 3-way synchronized finisher executing Kaelen, Garrett, and Serafina's combined kinetic combo
 * (2500 base damage, 500 poise damage, 0.10x dilation, +0.35 fatigue to both companions).
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteSovereignFinisherGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteSovereignFinisherGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	/** Direct C++ execution interface */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Zenith")
	bool ExecuteTripartiteFinisher(AActor* InstigatorActor, AActor* TargetBoss);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat|Zenith|Balancing")
	UAshenSyncFinisherBalanceDataAsset* BalanceDataAsset;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Zenith|Events")
	FOnTripartiteZenithExecutedSignature OnTripartiteZenithExecuted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Zenith")
	float FinisherDamage = 2500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Zenith")
	float PoiseDamage = 500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Zenith")
	float TimeDilationScale = 0.10f;
};
