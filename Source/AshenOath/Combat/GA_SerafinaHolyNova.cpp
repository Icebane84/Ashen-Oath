// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 165: GA_SerafinaHolyNova — Radiant Burst AoE

#include "GA_SerafinaHolyNova.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AbilitySystemComponent.h"

UGA_SerafinaHolyNova::UGA_SerafinaHolyNova()
{
	HolyDamage = 195.0f;
	NovaRadius = 600.0f;
	WeaknessDebuffDuration = 3.0f;
	WeaknessDamageReduction = 0.20f;
}

void UGA_SerafinaHolyNova::ActivateAbility(
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

	const FVector NovaOrigin = Owner->GetActorLocation();

	// Spatial query — find all enemy actors within the nova radius
	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		NovaOrigin,
		NovaRadius,
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
			HealthComp->ReceiveDamage(HolyDamage, Owner);
			HitCount++;

			UE_LOG(LogTemp, Log, TEXT("UGA_SerafinaHolyNova: Applied %.0f Holy dmg to '%s'. Radiant Weakness (%.0fs, -%.0f pct dmg) applied."),
				HolyDamage, *Target->GetName(), WeaknessDebuffDuration, WeaknessDamageReduction * 100.0f);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaHolyNova: Holy Nova DETONATED at '%s' — hit %d targets in %.0f unit radius."),
		*Owner->GetName(), HitCount, NovaRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
