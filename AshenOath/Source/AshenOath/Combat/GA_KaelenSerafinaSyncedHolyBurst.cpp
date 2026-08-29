// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_KaelenSerafinaSyncedHolyBurst.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UGA_KaelenSerafinaSyncedHolyBurst::UGA_KaelenSerafinaSyncedHolyBurst()
{
	Damage = 500.0f;
	Radius = 650.0f;
	BalanceDataAsset = nullptr;
}

bool UGA_KaelenSerafinaSyncedHolyBurst::ExecuteSyncedHolyBurst(AActor* InstigatorActor)
{
	if (!InstigatorActor)
	{
		return false;
	}

	UWorld* World = InstigatorActor->GetWorld();
	if (!World)
	{
		return false;
	}

	FSyncedHolyBurstBalancing Params;
	if (BalanceDataAsset)
	{
		Params = BalanceDataAsset->GetClampedHolyBurst();
	}
	else
	{
		Params.BaseDamage = Damage;
		Params.Radius = Radius;
		Params.SanityAndHealthHeal = 50.0f;
		Params.SerafinaFatigueCost = 0.20f;
	}

	// 1. AoE Damage
	TArray<AActor*> HitActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		World,
		InstigatorActor->GetActorLocation(),
		Params.Radius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{ InstigatorActor },
		HitActors
	);

	int32 HitCount = 0;
	for (AActor* Target : HitActors)
	{
		if (!Target || Target == InstigatorActor) continue;

		if (UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			HealthComp->ReceiveDamage(Params.BaseDamage, InstigatorActor);
			HitCount++;
		}
	}

	// 2. Heal Kaelen
	if (UAshenOath_HealthComponent* KaelenHealth = InstigatorActor->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		KaelenHealth->Heal(Params.SanityAndHealthHeal);
	}

	// 3. Add Serafina Fatigue
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(TEXT("Serafina"), Params.SerafinaFatigueCost);
		}
	}

	// 4. Modulate Holy radiant fuller emissives
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(1.0f, 0.95f, 0.6f, 1.0f), 4.0f);
	}

	if (OnSyncedHolyBurstExecuted.IsBound())
	{
		OnSyncedHolyBurstExecuted.Broadcast(Params.BaseDamage, Params.SanityAndHealthHeal, Params.SerafinaFatigueCost);
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenSerafinaSyncedHolyBurst: KAELEN + SERAFINA SYNCED HOLY BURST — %.0f Holy Dmg (Hit: %d, +%.0f HP Healed, +%.2f Serafina Fatigue)."),
		Params.BaseDamage, HitCount, Params.SanityAndHealthHeal, Params.SerafinaFatigueCost);

	return true;
}

void UGA_KaelenSerafinaSyncedHolyBurst::ActivateAbility(
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
	ExecuteSyncedHolyBurst(Owner);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
