// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 356: GA_KaelenSerafinaSyncedHolyBurst

#include "GA_KaelenSerafinaSyncedHolyBurst.h"
#include "AshenOath_HealthComponent.h"
#include "AshenResonanceAnchoringSyncComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenSerafinaSyncedHolyBurst::UGA_KaelenSerafinaSyncedHolyBurst()
{
	Damage = 500.0f;
	Radius = 650.0f;
}

void UGA_KaelenSerafinaSyncedHolyBurst::ActivateAbility(
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
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenSerafinaSyncedHolyBurst: KAELEN + SERAFINA SYNCED HOLY BURST — %.0f Holy/Phys damage to %d targets."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
