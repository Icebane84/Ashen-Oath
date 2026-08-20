// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedVoidShatter.generated.h"

/**
 * UGA_KaelenUnchainedVoidShatter
 *
 * Kaelen's ultimate Unchained Void ability dealing 850 Shadow damage and inflicting 5s Vulnerability in an 800u cone.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedVoidShatter : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedVoidShatter();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedVoidShatter")
	float Damage = 850.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedVoidShatter")
	float ConeRadius = 800.0f;
};
