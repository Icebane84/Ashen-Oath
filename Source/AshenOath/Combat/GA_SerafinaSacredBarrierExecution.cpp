// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 499: GA_SerafinaSacredBarrierExecution

#include "GA_SerafinaSacredBarrierExecution.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSacredBarrierExecution::UGA_SerafinaSacredBarrierExecution()
{
	ShieldAbsorbAmount = 1000.0f;
	Radius = 600.0f;
}

void UGA_SerafinaSacredBarrierExecution::ActivateAbility(
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

	int32 ShieldedCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->Heal(200.0f); // Shield burst heal
			ShieldedCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSacredBarrierExecution: SERAFINA SACRED BARRIER — %.0f Shield deployed to %d allies (600u Radius)."),
		ShieldAbsorbAmount, ShieldedCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
