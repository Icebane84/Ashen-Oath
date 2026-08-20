// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaTransference.generated.h"

/**
 * UGA_SerafinaTransference
 *
 * Gameplay Ability wrapping Serafina's "Healer's Burden" damage redirection.
 * Captures ally damage, applies Quiet Grace mitigation, transfers pain to Serafina,
 * and clears direct damage on ally target.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaTransference : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaTransference();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
