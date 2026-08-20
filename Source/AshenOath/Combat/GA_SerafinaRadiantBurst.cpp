// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 217: GA_SerafinaRadiantBurst

#include "GA_SerafinaRadiantBurst.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaRadiantBurst::UGA_SerafinaRadiantBurst()
{
	BaseDamage = 240.0f;
	BurstRadius = 450.0f;
	DazeDuration = 2.0f;
}

void UGA_SerafinaRadiantBurst::ActivateAbility(
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
		BurstRadius,
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
			HealthComp->ReceiveDamage(BaseDamage, Owner);
			HitCount++;

			UE_LOG(LogTemp, Log, TEXT("UGA_SerafinaRadiantBurst: Dealt %.0f Holy damage and %.1fs daze to '%s'."), BaseDamage, DazeDuration, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaRadiantBurst: RADIANT BURST executed by '%s' — %d targets hit in %.0fu radius."),
		*Owner->GetName(), HitCount, BurstRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
