// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 232: GA_GarrettExplosiveFlashPowder

#include "GA_GarrettExplosiveFlashPowder.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettExplosiveFlashPowder::UGA_GarrettExplosiveFlashPowder()
{
	Damage = 160.0f;
	BurstRadius = 350.0f;
	BlindDuration = 4.0f;
}

void UGA_GarrettExplosiveFlashPowder::ActivateAbility(
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
		BurstRadius,
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

			UE_LOG(LogTemp, Log, TEXT("UGA_GarrettExplosiveFlashPowder: Dealt %.0f Fire damage + %.1fs Blind to '%s'."), Damage, BlindDuration, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettExplosiveFlashPowder: EXPLOSIVE FLASH POWDER executed by '%s' — %d targets blinded in %.0fu radius."),
		*Owner->GetName(), HitCount, BurstRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
