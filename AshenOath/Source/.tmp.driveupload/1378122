// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenMartyrSacrifice.generated.h"

/**
 * UGA_KaelenMartyrSacrifice
 *
 * Kaelen's GAS ability sacrificing 30% current HP to heal nearby allies for 220 HP and cleanse companion Command Strain.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenMartyrSacrifice : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenMartyrSacrifice();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|MartyrSacrifice")
	float HealAmount = 220.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|MartyrSacrifice")
	float Radius = 600.0f;
};
