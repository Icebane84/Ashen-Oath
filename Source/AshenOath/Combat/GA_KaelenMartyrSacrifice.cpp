// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 332: GA_KaelenMartyrSacrifice

#include "GA_KaelenMartyrSacrifice.h"
#include "AshenOath_HealthComponent.h"
#include "AshenBurdenOfCommandComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenMartyrSacrifice::UGA_KaelenMartyrSacrifice()
{
	HealAmount = 220.0f;
	Radius = 600.0f;
}

void UGA_KaelenMartyrSacrifice::ActivateAbility(
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

	// Sacrifice Kaelen HP
	UAshenOath_HealthComponent* OwnerHealth = Owner->FindComponentByClass<UAshenOath_HealthComponent>();
	if (OwnerHealth)
	{
		OwnerHealth->ReceiveDamage(OwnerHealth->GetCurrentHealth() * 0.30f, Owner);
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
		TArray<AActor*>{ Owner },
		HitActors
	);

	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenBurdenOfCommandComponent* Burden = Target->FindComponentByClass<UAshenBurdenOfCommandComponent>();
		if (Burden)
		{
			Burden->RestAndRelieveStrain(50.0f);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenMartyrSacrifice: MARTYR SACRIFICE executed by '%s' — 30%% HP sacrificed to heal allies and relieve Command Strain."),
		*Owner->GetName());

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
