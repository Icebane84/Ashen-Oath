// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenInterruptedStruggleImprintGASAbility.generated.h"

/**
 * UAshenInterruptedStruggleImprintGASAbility
 * 
 * Buffers interrupted/failed Will Struggle attempts into an immutable FMemoryImprintPayload
 * ("Kaelen tried to speak/reach out but could not") queued for subsequent Heartstone compilation.
 */
UCLASS()
class ASHENOATH_API UAshenInterruptedStruggleImprintGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInterruptedStruggleImprintGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	/** Constructs the immutable memory imprint payload from the interrupted trial */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Memory")
	FMemoryImprintPayload CreateInterruptedStruggleImprint(
		const FWillTrialSessionSnapshot& SessionSnapshot,
		EWillContext Context,
		float CompletionRatio,
		FName MemorySiteId,
		FName EncounterId);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Memory")
	float BaseInterruptedTraumaMagnitude = 0.45f;
};
