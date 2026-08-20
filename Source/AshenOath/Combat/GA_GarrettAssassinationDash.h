// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettAssassinationDash.generated.h"

/**
 * UGA_GarrettAssassinationDash
 *
 * Garrett's lethal shadow assassination dash.
 * Teleports Garrett 600u behind an enemy target for a 380 Physical backstab strike + 3s Silence.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettAssassinationDash : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettAssassinationDash();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Assassination")
	float Damage = 380.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Assassination")
	float DashRange = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Assassination")
	float SilenceDuration = 3.0f;
};
