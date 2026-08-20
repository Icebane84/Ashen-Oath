// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 168: GA_AshbringerChargedSlam — Oathbringer Ground Slam AoE

#include "GA_AshbringerChargedSlam.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AbilitySystemComponent.h"

UGA_AshbringerChargedSlam::UGA_AshbringerChargedSlam()
{
	SlamDamage = 340.0f;
	SlamRadius = 500.0f;
	StaggerDuration = 2.0f;
	StaminaCost = 40.0f;
}

void UGA_AshbringerChargedSlam::ActivateAbility(
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

	// Deduct stamina cost
	UAshenOath_StaminaComponent* StaminaComp = Owner->FindComponentByClass<UAshenOath_StaminaComponent>();
	if (StaminaComp)
	{
		StaminaComp->ConsumeStamina(StaminaCost);
	}

	const FVector SlamOrigin = Owner->GetActorLocation();

	// SphereOverlap to detect all targets in slam radius
	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		SlamOrigin,
		SlamRadius,
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
			HealthComp->ReceiveDamage(SlamDamage, Owner);
			HitCount++;

			UE_LOG(LogTemp, Log, TEXT("UGA_AshbringerChargedSlam: %.0f Physical dmg to '%s'. Stagger applied (%.1fs)."),
				SlamDamage, *Target->GetName(), StaggerDuration);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_AshbringerChargedSlam: CHARGED SLAM at '%s' — hit %d targets in %.0f unit radius."),
		*Owner->GetName(), HitCount, SlamRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
