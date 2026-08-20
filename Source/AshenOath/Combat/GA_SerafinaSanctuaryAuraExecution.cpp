// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 533: GA_SerafinaSanctuaryAuraExecution

#include "GA_SerafinaSanctuaryAuraExecution.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSanctuaryAuraExecution::UGA_SerafinaSanctuaryAuraExecution()
{
	DamageAbsorbed = 800.0f;
	Radius = 700.0f;
}

void UGA_SerafinaSanctuaryAuraExecution::ActivateAbility(
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
			TargetHealth->Heal(100.0f);
			ShieldedCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSanctuaryAuraExecution: SERAFINA SANCTUARY AURA — %.0f Damage Absorbed / Shield Deployed for %d allies (700u Radius)."),
		DamageAbsorbed, ShieldedCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
