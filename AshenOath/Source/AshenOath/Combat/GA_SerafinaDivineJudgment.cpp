// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_SerafinaDivineJudgment.h"
#include "AshenOath_HealthComponent.h"
#include "AshenVFXPoolSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

UGA_SerafinaDivineJudgment::UGA_SerafinaDivineJudgment()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	DivineDamage = 300.0f;
	BlastRadius = 600.0f;
}

void UGA_SerafinaDivineJudgment::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* Avatar = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
	if (!Avatar)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UWorld* World = Avatar->GetWorld();
	if (!World)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	FVector Origin = Avatar->GetActorLocation();

	TArray<AActor*> OverlappedActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		World,
		Origin,
		BlastRadius,
		ObjectTypes,
		APawn::StaticClass(),
		TArray<AActor*>(),
		OverlappedActors);

	int32 HitCount = 0;
	for (AActor* Target : OverlappedActors)
	{
		if (!Target || Target == Avatar) continue;

		if (UAshenOath_HealthComponent* Health = Target->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			Health->ReceiveDamage(DivineDamage, Avatar);
			HitCount++;
		}
	}

	// Spawn pooled holy judgment explosion VFX
	if (UAshenVFXPoolSubsystem* VFXPool = World->GetSubsystem<UAshenVFXPoolSubsystem>())
	{
		VFXPool->SpawnPooledVFX(FName("VFX_SerafinaDivineJudgmentExplosion"), Origin, FRotator::ZeroRotator);
	}

	UE_LOG(LogTemp, Warning, TEXT("GA_SerafinaDivineJudgment: Executed Holy Blast dealing %.0f damage to %d targets!"), DivineDamage, HitCount);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
