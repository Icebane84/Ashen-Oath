// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 469: GA_SerafinaRadiantPurgeNova

#include "GA_SerafinaRadiantPurgeNova.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaRadiantPurgeNova::UGA_SerafinaRadiantPurgeNova()
{
	Damage = 500.0f;
	HealAmount = 250.0f;
	Radius = 800.0f;
}

void UGA_SerafinaRadiantPurgeNova::ActivateAbility(
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
		Radius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{},
		HitActors
	);

	int32 HitCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			if (Target == Owner)
			{
				TargetHealth->Heal(HealAmount);
			}
			else
			{
				TargetHealth->ReceiveDamage(Damage, Owner);
			}
			HitCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaRadiantPurgeNova: SERAFINA RADIANT PURGE NOVA — %.0f Holy damage / %.0f Heal to %d targets (800u Radius)."),
		Damage, HealAmount, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
