// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "GA_KaelenGarrettSyncedShadowStrike.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UGA_KaelenGarrettSyncedShadowStrike::UGA_KaelenGarrettSyncedShadowStrike()
{
	Damage = 600.0f;
	Radius = 500.0f;
	BalanceDataAsset = nullptr;
}

bool UGA_KaelenGarrettSyncedShadowStrike::ExecuteSyncedShadowStrike(AActor* InstigatorActor, AActor* TargetActor)
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

	FSyncedShadowStrikeBalancing Params;
	if (BalanceDataAsset)
	{
		Params = BalanceDataAsset->GetClampedShadowStrike();
	}
	else
	{
		Params.BaseDamage = Damage;
		Params.Radius = Radius;
		Params.StaggeredMultiplier = 1.8f;
		Params.GarrettFatigueCost = 0.25f;
	}

	float ActualDamage = Params.BaseDamage;
	int32 HitCount = 0;

	if (TargetActor)
	{
		// Check target posture/state for stagger multiplier
		if (UAshenOath_PoiseComponent* TargetPoise = TargetActor->FindComponentByClass<UAshenOath_PoiseComponent>())
		{
			if (TargetPoise->GetCurrentPoise() <= 0.0f)
			{
				ActualDamage *= Params.StaggeredMultiplier;
			}
		}

		if (UAshenOath_HealthComponent* TargetHealth = TargetActor->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			TargetHealth->ReceiveDamage(ActualDamage, InstigatorActor);
			HitCount++;
		}
	}
	else
	{
		// AoE Overlap
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

		for (AActor* Target : HitActors)
		{
			if (!Target || Target == InstigatorActor) continue;

			float TargetDamage = Params.BaseDamage;
			if (UAshenOath_PoiseComponent* TargetPoise = Target->FindComponentByClass<UAshenOath_PoiseComponent>())
			{
				if (TargetPoise->GetCurrentPoise() <= 0.0f)
				{
					TargetDamage *= Params.StaggeredMultiplier;
				}
			}

			if (UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>())
			{
				HealthComp->ReceiveDamage(TargetDamage, InstigatorActor);
				HitCount++;
			}
		}
	}

	// Add Garrett Fatigue
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(TEXT("Garrett"), Params.GarrettFatigueCost);
		}
	}

	// Modulate shadow fuller emissives
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(0.15f, 0.05f, 0.35f, 1.0f), 3.5f);
	}

	if (OnSyncedShadowStrikeExecuted.IsBound())
	{
		OnSyncedShadowStrikeExecuted.Broadcast(ActualDamage, Params.GarrettFatigueCost, HitCount);
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenGarrettSyncedShadowStrike: KAELEN + GARRETT SYNCED SHADOW STRIKE — %.0f Damage (Hit: %d, +%.2f Garrett Fatigue)."),
		ActualDamage, HitCount, Params.GarrettFatigueCost);

	return true;
}

void UGA_KaelenGarrettSyncedShadowStrike::ActivateAbility(
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
	ExecuteSyncedShadowStrike(Owner, nullptr);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
