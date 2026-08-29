// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenInscribeGuardSigilGASAbility.generated.h"

/**
 * UAshenInscribeGuardSigilGASAbility
 * 
 * Anvil Metallurgy: Inscribes and sockets an ancient runic sigil into one of Oathbringer's 4 guard sockets at a campfire traveling anvil.
 */
UCLASS()
class ASHENOATH_API UAshenInscribeGuardSigilGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInscribeGuardSigilGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	EGuardSigilSocket TargetSocket = EGuardSigilSocket::VomTagSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	ESigilResonanceEffect SigilToInscribe = ESigilResonanceEffect::ShatteredColossus;
};
