// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 182: GA_KaelenWhirlwindSlash

#include "GA_KaelenWhirlwindSlash.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UGA_KaelenWhirlwindSlash::UGA_KaelenWhirlwindSlash()
{
	Damage = 280.0f;
	Radius = 450.0f;
	StaminaCost = 45.0f;
	KnockbackImpulse = 800.0f;
}

void UGA_KaelenWhirlwindSlash::ActivateAbility(
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

	// Consume stamina
	UAshenOath_StaminaComponent* StaminaComp = Owner->FindComponentByClass<UAshenOath_StaminaComponent>();
	if (StaminaComp)
	{
		StaminaComp->ConsumeStamina(StaminaCost);
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

			// Apply knockback impulse if target is character
			if (ACharacter* TargetChar = Cast<ACharacter>(Target))
			{
				FVector KnockbackDir = (Target->GetActorLocation() - Origin).GetSafeNormal2D();
				TargetChar->LaunchCharacter(KnockbackDir * KnockbackImpulse + FVector(0, 0, 200.0f), true, true);
			}

			UE_LOG(LogTemp, Log, TEXT("UGA_KaelenWhirlwindSlash: Dealt %.0f damage and knockback to '%s'."), Damage, *Target->GetName());
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenWhirlwindSlash: WHIRLWIND SLASH executed by '%s' — hit %d targets in %.0f unit radius."),
		*Owner->GetName(), HitCount, Radius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
