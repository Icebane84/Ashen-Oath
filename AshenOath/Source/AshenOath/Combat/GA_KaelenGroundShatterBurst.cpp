// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 277: GA_KaelenGroundShatterBurst

#include "GA_KaelenGroundShatterBurst.h"
#include "AshenOath_HealthComponent.h"
#include "AshenDungeonDestructibleWallComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenGroundShatterBurst::UGA_KaelenGroundShatterBurst()
{
	Damage = 480.0f;
	Radius = 550.0f;
}

void UGA_KaelenGroundShatterBurst::ActivateAbility(
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
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

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

		UAshenDungeonDestructibleWallComponent* WallComp = Target->FindComponentByClass<UAshenDungeonDestructibleWallComponent>();
		if (WallComp)
		{
			WallComp->ReceiveStructuralDamage(Damage);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGroundShatterBurst: SEISMIC GROUND SHATTER BURST executed by '%s' — %d targets struck in %.0fu radius."),
		*Owner->GetName(), HitCount, Radius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
