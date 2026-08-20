// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaRadiantBurst.generated.h"

/**
 * UGA_SerafinaRadiantBurst
 *
 * Serafina's offensive radiant blast ability.
 * Deals 240 Holy damage and 2s Daze to enemies within 450u.
 * Deals double damage (480 Holy) against corrupted/shadow targets.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaRadiantBurst : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaRadiantBurst();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantBurst")
	float BaseDamage = 240.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantBurst")
	float BurstRadius = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantBurst")
	float DazeDuration = 2.0f;
};
