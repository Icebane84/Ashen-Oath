// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 212: GA_KaelenGroundShatterStrike

#include "GA_KaelenGroundShatterStrike.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"

UGA_KaelenGroundShatterStrike::UGA_KaelenGroundShatterStrike()
{
	Damage = 310.0f;
	ConeRadius = 400.0f;
	KnockdownDuration = 1.5f;
}

void UGA_KaelenGroundShatterStrike::ActivateAbility(
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
		ConeRadius,
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

			if (ACharacter* TargetChar = Cast<ACharacter>(Target))
			{
				TargetChar->LaunchCharacter(FVector(0, 0, -500.0f), true, true); // Ground slam force
			}

			UE_LOG(LogTemp, Log, TEXT("UGA_KaelenGroundShatterStrike: Dealt %.0f Phys damage and %.1fs knockdown to '%s'."), Damage, KnockdownDuration, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGroundShatterStrike: GROUND SHATTER STRIKE executed by '%s' — %d targets hit in %.0fu cone."),
		*Owner->GetName(), HitCount, ConeRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
