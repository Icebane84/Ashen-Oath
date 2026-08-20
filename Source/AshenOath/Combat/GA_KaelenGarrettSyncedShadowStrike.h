// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGarrettSyncedShadowStrike.generated.h"

/**
 * UGA_KaelenGarrettSyncedShadowStrike
 *
 * Dual-character GAS ability executing a 600 Phys shadow teleport assassination with Garrett.
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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedShadowStrike")
	float Damage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SyncedShadowStrike")
	float Radius = 500.0f;
};
