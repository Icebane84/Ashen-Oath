// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 262: GA_GarrettAssassinationDash

#include "GA_GarrettAssassinationDash.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"

UGA_GarrettAssassinationDash::UGA_GarrettAssassinationDash()
{
	Damage = 380.0f;
	DashRange = 600.0f;
	SilenceDuration = 3.0f;
}

void UGA_GarrettAssassinationDash::ActivateAbility(
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
		DashRange,
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
			// Teleport behind target
			const FVector TargetLocation = Target->GetActorLocation();
			const FVector TeleportLocation = TargetLocation - (Target->GetActorForwardVector() * 120.0f);

			if (ACharacter* OwnerChar = Cast<ACharacter>(Owner))
			{
				OwnerChar->SetActorLocation(TeleportLocation);
			}

			HealthComp->ReceiveDamage(Damage, Owner);
			HitCount++;

			UE_LOG(LogTemp, Log, TEXT("UGA_GarrettAssassinationDash: Dealt %.0f Phys backstab damage + %.1fs Silence to '%s'."), Damage, SilenceDuration, *Target->GetName());
			break; // Single target execution strike
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettAssassinationDash: ASSASSINATION DASH executed by '%s' — %d targets struck."),
		*Owner->GetName(), HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
