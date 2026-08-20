// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_SerafinaRadiantAegis.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

UGA_SerafinaRadiantAegis::UGA_SerafinaRadiantAegis()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	BarrierAmount = 150.0f;
	BarrierDuration = 8.0f;
}

void UGA_SerafinaRadiantAegis::ActivateAbility(
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

	// Apply barrier (heal 150 HP / increase max barrier)
	if (UAshenOath_HealthComponent* Health = Avatar->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		Health->Heal(BarrierAmount);
	}

	if (UAshenOath_PoiseComponent* Poise = Avatar->FindComponentByClass<UAshenOath_PoiseComponent>())
	{
		Poise->ResetPoise();
	}

	UE_LOG(LogTemp, Warning, TEXT("GA_SerafinaRadiantAegis: Applied 150 HP Holy Aegis Barrier to '%s'!"), *Avatar->GetName());

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
