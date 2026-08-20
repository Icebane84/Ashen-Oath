// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 407: GA_GarrettPoisonSmokeGrid

#include "GA_GarrettPoisonSmokeGrid.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettPoisonSmokeGrid::UGA_GarrettPoisonSmokeGrid()
{
	Damage = 300.0f;
	GridRadius = 600.0f;
}

void UGA_GarrettPoisonSmokeGrid::ActivateAbility(
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
		GridRadius,
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

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettPoisonSmokeGrid: GARRETT POISON SMOKE GRID — Dealt %.0f damage to %d targets (600u Radius)."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
