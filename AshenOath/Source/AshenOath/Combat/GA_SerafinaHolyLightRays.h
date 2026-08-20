// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaHolyLightRays.generated.h"

/**
 * UGA_SerafinaHolyLightRays
 *
 * Serafina's channelled radiant light rays ability.
 * Deals 320 Holy damage to all enemies in a 600u line while purging debuffs from allies.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaHolyLightRays : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaHolyLightRays();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyLightRays")
	float Damage = 320.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyLightRays")
	float LineLength = 600.0f;
};
