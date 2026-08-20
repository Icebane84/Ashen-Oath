// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSacredGround.generated.h"

/**
 * UGA_SerafinaSacredGround
 *
 * Serafina's Consecrated Ground ability.
 * Creates a 600-unit holy zone that ticks every second for 8 seconds:
 *   - Deals 35 Holy damage/sec to enemies
 *   - Heals allies for 15 HP/sec
 * Uses UKismetSystemLibrary::SphereOverlapActors.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSacredGround : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSacredGround();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGround")
	float Radius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGround")
	float Duration = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGround")
	float DamagePerTick = 35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGround")
	float HealPerTick = 15.0f;
};
