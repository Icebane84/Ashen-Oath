// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 372: GA_KaelenResonanceShiftAttack

#include "GA_KaelenResonanceShiftAttack.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenResonanceShiftAttack::UGA_KaelenResonanceShiftAttack()
{
	Damage = 480.0f;
	ResonanceShiftDelta = 35.0f;
}

void UGA_KaelenResonanceShiftAttack::ActivateAbility(
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
		450.0f,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		HitActors
	);

	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->ReceiveDamage(Damage, Owner);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenResonanceShiftAttack: RESONANCE SHIFT ATTACK EXECUTED — Dealt %.0f damage and shifted Resonance by %+.0f."),
		Damage, ResonanceShiftDelta);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
