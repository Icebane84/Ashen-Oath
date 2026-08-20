// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 227 (Refactored): GA_KaelenGreatswordPommelStrike

#include "GA_KaelenGreatswordPommelStrike.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"

UGA_KaelenGreatswordPommelStrike::UGA_KaelenGreatswordPommelStrike()
{
	Damage = 180.0f;
	PoiseDamage = 90.0f;
	StrikeRadius = 300.0f;
}

void UGA_KaelenGreatswordPommelStrike::ActivateAbility(
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
		StrikeRadius,
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

			UAshenOath_PoiseComponent* PoiseComp = Target->FindComponentByClass<UAshenOath_PoiseComponent>();
			if (PoiseComp)
			{
				PoiseComp->ApplyPoiseDamage(PoiseDamage);
			}

			if (ACharacter* TargetChar = Cast<ACharacter>(Target))
			{
				const FVector StrikeDir = (Target->GetActorLocation() - Origin).GetSafeNormal2D();
				TargetChar->LaunchCharacter(StrikeDir * 900.0f + FVector(0, 0, 150.0f), true, true);
			}

			UE_LOG(LogTemp, Log, TEXT("UGA_KaelenGreatswordPommelStrike: Dealt %.0f Phys damage + %.0f Poise damage to '%s'."), Damage, PoiseDamage, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGreatswordPommelStrike: OATHBRINGER POMMEL STRIKE executed by '%s' — %d targets hit in %.0fu radius."),
		*Owner->GetName(), HitCount, StrikeRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
