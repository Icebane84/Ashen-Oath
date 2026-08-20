// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 316: GA_KaelenOathBurnExecution

#include "GA_KaelenOathBurnExecution.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOathBurnComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_KaelenOathBurnExecution::UGA_KaelenOathBurnExecution()
{
	Damage = 650.0f;
	Radius = 450.0f;
}

void UGA_KaelenOathBurnExecution::ActivateAbility(
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

	// Trigger Oath Burn penalty
	UAshenOathBurnComponent* BurnComp = Owner->FindComponentByClass<UAshenOathBurnComponent>();
	if (BurnComp)
	{
		BurnComp->TriggerOathBurn();
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

	int32 HitCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(Damage, Owner);
			HitCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenOathBurnExecution: OATH BURN EXECUTION SLAM executed by '%s' — %.0f Phys/Holy damage to %d targets."),
		*Owner->GetName(), Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
