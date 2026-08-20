// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaAegisShieldSanctuary.generated.h"

/**
 * UGA_SerafinaAegisShieldSanctuary
 *
 * Serafina's grand ultimate GAS ability creating a 900u Holy Dome providing complete damage immunity & restoring 400 Shield HP over 10.0s.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaAegisShieldSanctuary : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaAegisShieldSanctuary();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisShieldSanctuary")
	float ShieldRestoreAmount = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisShieldSanctuary")
	float DomeRadius = 900.0f;
};
