// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenApplyAlchemicalCoatingGASAbility.generated.h"

/**
 * UAshenApplyAlchemicalCoatingGASAbility
 * 
 * Garrett's Flask Application: Applies chosen alchemical coating (Naphtha, Frost, Acid, Copper) to Oathbringer granting 5 empowered strike charges.
 */
UCLASS()
class ASHENOATH_API UAshenApplyAlchemicalCoatingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenApplyAlchemicalCoatingGASAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	EAlchemicalBladeCoating CoatingToApply = EAlchemicalBladeCoating::PyrophoricNaphtha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	int32 ApplicationCharges = 5;
};
