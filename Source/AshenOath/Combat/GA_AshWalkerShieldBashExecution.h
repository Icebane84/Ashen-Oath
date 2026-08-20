// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_AshWalkerShieldBashExecution.generated.h"

/**
 * UGA_AshWalkerShieldBashExecution
 *
 * Heavy elite shield bash dealing 600 damage and knocking down players in a 350u arc.
 */
UCLASS()
class ASHENOATH_API UGA_AshWalkerShieldBashExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_AshWalkerShieldBashExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShieldBashExecution")
	float Damage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShieldBashExecution")
	float Radius = 350.0f;
};
