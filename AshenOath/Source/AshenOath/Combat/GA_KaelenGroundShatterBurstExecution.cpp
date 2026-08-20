// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 464: GA_KaelenGroundShatterBurstExecution

#include "GA_KaelenGroundShatterBurstExecution.h"
#include "AshenOath_HealthComponent.h"
#include "AshenCombatEnvironmentalImpactSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"

UGA_KaelenGroundShatterBurstExecution::UGA_KaelenGroundShatterBurstExecution()
{
	Damage = 800.0f;
	Radius = 500.0f;
}

void UGA_KaelenGroundShatterBurstExecution::ActivateAbility(
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

		UAshenOath_HealthComponent* TargetHealth = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (TargetHealth)
		{
			TargetHealth->ReceiveDamage(Damage, Owner);
			HitCount++;
		}
	}

	if (UWorld* World = Owner->GetWorld())
	{
		if (UAshenCombatEnvironmentalImpactSubsystem* ImpactSubsystem = World->GetSubsystem<UAshenCombatEnvironmentalImpactSubsystem>())
		{
			ImpactSubsystem->RegisterHeavyCombatImpact(Origin, Radius, 80.0f);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGroundShatterBurstExecution: KAELEN GROUND SHATTER BURST — %.0f Phys damage to %d targets (500u Radius)."),
		Damage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
