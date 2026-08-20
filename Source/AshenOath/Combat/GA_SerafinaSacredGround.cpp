// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 188: GA_SerafinaSacredGround

#include "GA_SerafinaSacredGround.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSacredGround::UGA_SerafinaSacredGround()
{
	Radius = 600.0f;
	Duration = 8.0f;
	DamagePerTick = 35.0f;
	HealPerTick = 15.0f;
}

void UGA_SerafinaSacredGround::ActivateAbility(
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

	const FVector GroundLocation = Owner->GetActorLocation();

	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		GroundLocation,
		Radius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>(),
		OverlappingActors
	);

	int32 EnemyCount = 0;
	int32 AllyCount = 0;

	for (AActor* Target : OverlappingActors)
	{
		if (!Target) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (!HealthComp) continue;

		if (Target == Owner)
		{
			// Heal self/ally
			HealthComp->Heal(HealPerTick);
			AllyCount++;
		}
		else
		{
			// Damage enemy
			HealthComp->ReceiveDamage(DamagePerTick, Owner);
			EnemyCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSacredGround: SACRED GROUND spawned at (%.0f, %.0f, %.0f) — %.0fs duration, %d enemies hit (%.0f dmg), %d allies healed (%.0f HP)."),
		GroundLocation.X, GroundLocation.Y, GroundLocation.Z, Duration, EnemyCount, DamagePerTick, AllyCount, HealPerTick);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
