// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 247: GA_GarrettTripleDaggerFan

#include "GA_GarrettTripleDaggerFan.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettTripleDaggerFan::UGA_GarrettTripleDaggerFan()
{
	BaseDamage = 90.0f;
	PoisonDamagePerSec = 15.0f;
	FanRadius = 450.0f;
}

void UGA_GarrettTripleDaggerFan::ActivateAbility(
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
		FanRadius,
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

			UE_LOG(LogTemp, Log, TEXT("UGA_GarrettTripleDaggerFan: Dealt %.0f Phys damage + %.0f/s Poison to '%s'."), BaseDamage, PoisonDamagePerSec, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettTripleDaggerFan: TRIPLE DAGGER FAN executed by '%s' — %d targets struck in %.0fu fan."),
		*Owner->GetName(), HitCount, FanRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
