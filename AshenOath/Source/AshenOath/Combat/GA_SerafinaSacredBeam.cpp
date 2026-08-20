// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 267: GA_SerafinaSacredBeam

#include "GA_SerafinaSacredBeam.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSacredBeam::UGA_SerafinaSacredBeam()
{
	Damage = 360.0f;
	BeamRange = 700.0f;
	BlindDuration = 2.5f;
}

void UGA_SerafinaSacredBeam::ActivateAbility(
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
		BeamRange,
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

			UE_LOG(LogTemp, Log, TEXT("UGA_SerafinaSacredBeam: Dealt %.0f Holy damage + %.1fs Blind to '%s'."), Damage, BlindDuration, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSacredBeam: SACRED BEAM executed by '%s' — %d targets struck in %.0fu line."),
		*Owner->GetName(), HitCount, BeamRange);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
