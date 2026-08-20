// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_KaelenGuardBreakCounter.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"

UGA_KaelenGuardBreakCounter::UGA_KaelenGuardBreakCounter()
{
	CounterDamage = 180.0f;
	PoiseDamage = 85.0f;
	CounterRadius = 300.0f;
}

void UGA_KaelenGuardBreakCounter::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	AActor* Avatar = ActorInfo->AvatarActor.Get();
	FVector StartLoc = Avatar->GetActorLocation();

	TArray<AActor*> OverlappedActors;
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(Avatar);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Avatar->GetWorld(),
		StartLoc,
		CounterRadius,
		ObjectTypes,
		APawn::StaticClass(),
		IgnoreActors,
		OverlappedActors
	);

	for (AActor* Target : OverlappedActors)
	{
		if (Target && Target != Avatar)
		{
			if (UAshenOath_HealthComponent* Health = Target->FindComponentByClass<UAshenOath_HealthComponent>())
			{
				Health->ReceiveDamage(CounterDamage, Avatar);
			}

			if (UAshenOath_PoiseComponent* Poise = Target->FindComponentByClass<UAshenOath_PoiseComponent>())
			{
				Poise->ApplyPoiseDamage(PoiseDamage);
			}

			OnCounterExecuted.Broadcast(Target, CounterDamage);
			UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGuardBreakCounter: Executed guard break counter against '%s' for %.1f damage!"), *Target->GetName(), CounterDamage);
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
