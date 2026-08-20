// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 412: GA_KaelenEarthshakerExecution

#include "GA_KaelenEarthshakerExecution.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenEarthshakerExecution::UGA_KaelenEarthshakerExecution()
{
	Damage = 700.0f;
	Radius = 500.0f;
}

void UGA_KaelenEarthshakerExecution::ActivateAbility(
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenEarthshakerExecution: KAELEN EARTHSHAKER EXECUTION — %.0f Phys damage to %d targets (500u Slam Radius)."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
