// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 479: GA_BossAbominationVoidSmashExecution

#include "GA_BossAbominationVoidSmashExecution.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_BossAbominationVoidSmashExecution::UGA_BossAbominationVoidSmashExecution()
{
	Damage = 900.0f;
	Radius = 700.0f;
}

void UGA_BossAbominationVoidSmashExecution::ActivateAbility(
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

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->ReceiveDamage(Damage, Owner);
			HitCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_BossAbominationVoidSmashExecution: BOSS VOID SMASH EXECUTION — %.0f Void damage to %d targets (700u Radius)."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
