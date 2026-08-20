// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenSerafinaSyncedHolyBurst.generated.h"

/**
 * UGA_KaelenSerafinaSyncedHolyBurst
 *
 * Dual-character GAS ability executing a 500 Holy/Phys synchronized blast and purging debuffs.
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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedHolyBurst")
	float Damage = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedHolyBurst")
	float Radius = 650.0f;
};
