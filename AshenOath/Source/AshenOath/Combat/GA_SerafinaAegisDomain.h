// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaAegisDomain.generated.h"

/**
 * UGA_SerafinaAegisDomain
 *
 * Serafina's ultimate aegis domain ability.
 * Creates a 600u holy sanctuary dome granting CC immunity & 300 Shield HP to allies for 12.0s.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaAegisDomain : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaAegisDomain();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisDomain")
	float DomainRadius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisDomain")
	float ShieldHealth = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisDomain")
	float DomainDuration = 12.0f;
};
