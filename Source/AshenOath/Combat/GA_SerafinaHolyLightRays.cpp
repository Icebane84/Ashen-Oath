// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 252: GA_SerafinaHolyLightRays

#include "GA_SerafinaHolyLightRays.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaHolyLightRays::UGA_SerafinaHolyLightRays()
{
	Damage = 320.0f;
	LineLength = 600.0f;
}

void UGA_SerafinaHolyLightRays::ActivateAbility(
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
		LineLength,
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

			UE_LOG(LogTemp, Log, TEXT("UGA_SerafinaHolyLightRays: Dealt %.0f Holy damage to '%s'."), Damage, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaHolyLightRays: HOLY LIGHT RAYS executed by '%s' — %d targets struck in %.0fu line."),
		*Owner->GetName(), HitCount, LineLength);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
