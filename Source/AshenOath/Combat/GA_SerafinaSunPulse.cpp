// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 238: GA_SerafinaSunPulse

#include "GA_SerafinaSunPulse.h"
#include "AshenOath_HealthComponent.h"
#include "AshenShroudKnightBossActor.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_SerafinaSunPulse::UGA_SerafinaSunPulse()
{
	Damage = 280.0f;
	PulseRadius = 500.0f;
}

void UGA_SerafinaSunPulse::ActivateAbility(
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
		PulseRadius,
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

		if (AAshenShroudKnightBossActor* Boss = Cast<AAshenShroudKnightBossActor>(Target))
		{
			Boss->ForcePhysicalAnchor(true);
			UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSunPulse: SUN PULSE ANCHORED SHROUD-KNIGHT!"));
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaSunPulse: SERAFINA SUN PULSE executed by '%s' — %d targets hit in %.0fu radius."),
		*Owner->GetName(), HitCount, PulseRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
