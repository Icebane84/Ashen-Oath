// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_OathbringerCombo.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_OathbringerCombo::UGA_OathbringerCombo()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	ComboStep = 1;
	BaseDamage = 35.0f;
	HeavyChargeMultiplier = 2.0f;
	StaminaCostLight = 15.0f;
	StaminaCostHeavy = 35.0f;
}

void UGA_OathbringerCombo::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (!Avatar)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	float StaminaCost = (ComboStep == 3) ? StaminaCostHeavy : StaminaCostLight;

	// Consume Stamina
	if (UAshenOath_StaminaComponent* Stamina = Avatar->FindComponentByClass<UAshenOath_StaminaComponent>())
	{
		if (!Stamina->ConsumeStamina(StaminaCost))
		{
			UE_LOG(LogTemp, Warning, TEXT("GA_OathbringerCombo: Not enough stamina for Combo Step %d!"), ComboStep);
			EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
			return;
		}
	}

	float FinalDamage = BaseDamage * (ComboStep == 3 ? HeavyChargeMultiplier : (1.0f + (ComboStep - 1) * 0.25f));

	UE_LOG(LogTemp, Log, TEXT("GA_OathbringerCombo: Executing Combo Step %d — Final Damage: %.1f | Stamina Cost: %.1f"),
		ComboStep, FinalDamage, StaminaCost);

	// Advance combo step or loop back
	ComboStep = (ComboStep % 3) + 1;

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
