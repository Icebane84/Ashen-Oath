// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 347: GA_GarrettShadowSnareTrap

#include "GA_GarrettShadowSnareTrap.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettShadowSnareTrap::UGA_GarrettShadowSnareTrap()
{
	SnareDamage = 200.0f;
	TrapRadius = 350.0f;
}

void UGA_GarrettShadowSnareTrap::ActivateAbility(
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
		TrapRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ Owner },
		HitActors
	);

	int32 SnaredCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target || Target == Owner) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(SnareDamage, Owner);
			SnaredCount++;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettShadowSnareTrap: SHADOW SNARE TRAP ARMED by '%s' — %.0f damage to %d targets (4.0s Snare)."),
		*Owner->GetName(), SnareDamage, SnaredCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
