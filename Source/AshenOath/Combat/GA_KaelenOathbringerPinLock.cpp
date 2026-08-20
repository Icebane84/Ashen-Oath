// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 241: GA_KaelenOathbringerPinLock

#include "GA_KaelenOathbringerPinLock.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenOathbringerPinLock::UGA_KaelenOathbringerPinLock()
{
	Damage = 220.0f;
	PinRadius = 350.0f;
	PinDuration = 3.0f;
}

void UGA_KaelenOathbringerPinLock::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* Owner = ActorInfo->OwnerActor.Get();
	if (!Owner)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	const FVector Origin = Owner->GetActorLocation();

	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		Origin,
		PinRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		HitActors
	);

	int32 HitCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(Damage, Owner);
			HitCount++;

			UAshenOath_PoiseComponent* PoiseComp = Target->FindComponentByClass<UAshenOath_PoiseComponent>();
			if (PoiseComp)
			{
				PoiseComp->ApplyPoiseDamage(120.0f);
			}

			UE_LOG(LogTemp, Log, TEXT("UGA_KaelenOathbringerPinLock: Dealt %.0f Phys damage and pinned '%s' for %.1fs."), Damage, *Target->GetName(), PinDuration);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenOathbringerPinLock: OATHBRINGER PIN LOCK executed by '%s' — %d targets pinned in %.0fu radius."),
		*Owner->GetName(), HitCount, PinRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
