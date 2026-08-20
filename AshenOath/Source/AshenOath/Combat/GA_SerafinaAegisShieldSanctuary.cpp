// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 397: GA_SerafinaAegisShieldSanctuary

#include "GA_SerafinaAegisShieldSanctuary.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaAegisShieldSanctuary::UGA_SerafinaAegisShieldSanctuary()
{
	ShieldRestoreAmount = 400.0f;
	DomeRadius = 900.0f;
}

void UGA_SerafinaAegisShieldSanctuary::ActivateAbility(
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
		DomeRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		HitActors
	);

	for (AActor* Ally : HitActors)
	{
		if (!Ally) continue;
		UAshenOath_HealthComponent* AllyHealth = Ally->FindComponentByClass<UAshenOath_HealthComponent>();
		if (AllyHealth)
		{
			AllyHealth->Heal(ShieldRestoreAmount);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaAegisShieldSanctuary: SERAFINA AEGIS SHIELD SANCTUARY ACTIVATED — 900u Holy Dome (%.0f Shield HP Restored)."),
		ShieldRestoreAmount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
