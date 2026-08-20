// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 443: GA_SerafinaSacredGroundSanctuary

#include "GA_SerafinaSacredGroundSanctuary.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSacredGroundSanctuary::UGA_SerafinaSacredGroundSanctuary()
{
	HealAmount = 350.0f;
	Radius = 700.0f;
}

void UGA_SerafinaSacredGroundSanctuary::ActivateAbility(
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
		TArray<AActor*>{},
		HitActors
	);

	int32 HealedCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->Heal(HealAmount);
			HealedCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSacredGroundSanctuary: SERAFINA SACRED GROUND — %.0f HP restored to %d allies (700u Radius)."),
		HealAmount, HealedCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
