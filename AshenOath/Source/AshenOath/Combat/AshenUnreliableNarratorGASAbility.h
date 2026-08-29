// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenUnreliableNarratorGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMirageDispelledSignature, float, StaminaCost, float, SanityHealed);

/**
 * UAshenUnreliableNarratorGASAbility
 * GAS Ability releasing a focused somatic willpower pulse, consuming 15 stamina to dispel
 * active hallucinatory mirages and restoring interface state to DiegeticOnly.
 */
UCLASS()
class ASHENOATH_API UAshenUnreliableNarratorGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenUnreliableNarratorGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Unreliable")
	float StaminaCost = 15.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Unreliable")
	float SanityClarityHeal = 15.0f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Unreliable|Events")
	FOnMirageDispelledSignature OnMirageDispelled;

	/** Executes the willpower pulse dispelling deceptive mirages and restoring mental clarity */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool DispelHallucinatoryMirage(AActor* InstigatorActor);
};
