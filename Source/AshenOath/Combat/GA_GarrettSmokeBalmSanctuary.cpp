// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 457: GA_GarrettSmokeBalmSanctuary

#include "GA_GarrettSmokeBalmSanctuary.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettSmokeBalmSanctuary::UGA_GarrettSmokeBalmSanctuary()
{
	HealPerSecond = 50.0f;
	Radius = 500.0f;
}

void UGA_GarrettSmokeBalmSanctuary::ActivateAbility(
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
			TargetHealth->Heal(HealPerSecond);
			HealedCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSmokeBalmSanctuary: GARRETT SMOKE BALM — %.0f HP restored to %d allies in smoke zone."),
		HealPerSecond, HealedCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
