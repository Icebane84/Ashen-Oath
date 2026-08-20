// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 422: GA_SerafinaSunfallNova

#include "GA_SerafinaSunfallNova.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSunfallNova::UGA_SerafinaSunfallNova()
{
	Damage = 650.0f;
	Radius = 1000.0f;
}

void UGA_SerafinaSunfallNova::ActivateAbility(
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSunfallNova: SERAFINA SUNFALL NOVA — %.0f Holy damage to %d targets (1000u Radius)."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
