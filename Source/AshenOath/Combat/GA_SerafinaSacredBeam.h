// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSacredBeam.generated.h"

/**
 * UGA_SerafinaSacredBeam
 *
 * Serafina's channelled sacred beam attack.
 * Deals 360 Holy damage + 2.5s Blind to all targets in a 700u line.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSacredBeam : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSacredBeam();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredBeam")
	float Damage = 360.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredBeam")
	float BeamRange = 700.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredBeam")
	float BlindDuration = 2.5f;
};
