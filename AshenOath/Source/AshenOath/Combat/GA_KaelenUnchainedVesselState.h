// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedVesselState.generated.h"

/**
 * UGA_KaelenUnchainedVesselState
 *
 * Kaelen's GAS ability transitioning his soul vector into the corrupted "Unchained Vessel" state (UMB-SYS-005).
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedVesselState : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedVesselState();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedVessel")
	float IntegrationDebtSurge = 25.0f;
};
