// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 494: GA_KaelenParryCounterExecution

#include "GA_KaelenParryCounterExecution.h"
#include "AshenOath_HealthComponent.h"
#include "AshenEnemyPoiseBreakComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenParryCounterExecution::UGA_KaelenParryCounterExecution()
{
	Damage = 1000.0f;
}

void UGA_KaelenParryCounterExecution::ActivateAbility(
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
		350.0f,
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

			if (UAshenEnemyPoiseBreakComponent* PoiseComp = Target->FindComponentByClass<UAshenEnemyPoiseBreakComponent>())
			{
				PoiseComp->ApplyPoiseDamage(200.0f); // Instant break
			}
			HitCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenParryCounterExecution: PARRY COUNTER EXECUTION — %.0f damage + Instant Poise Break to %d targets."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
