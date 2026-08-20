// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaLorekeeperInsightExecution.generated.h"

/**
 * UGA_SerafinaLorekeeperInsightExecution
 *
 * Serafina's GAS ability decrypting raw combat imprints during combat or rest.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaLorekeeperInsightExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaLorekeeperInsightExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|LorekeeperInsightExecution")
	float SanityRestored = 300.0f;
};
