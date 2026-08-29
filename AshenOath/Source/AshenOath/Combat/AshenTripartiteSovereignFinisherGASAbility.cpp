// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenTripartiteSovereignFinisherGASAbility.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenTripartiteSovereignFinisherGASAbility::UAshenTripartiteSovereignFinisherGASAbility()
{
	FinisherDamage = 2500.0f;
	PoiseDamage = 500.0f;
	TimeDilationScale = 0.10f;
	BalanceDataAsset = nullptr;
}

bool UAshenTripartiteSovereignFinisherGASAbility::ExecuteTripartiteFinisher(AActor* InstigatorActor, AActor* TargetBoss)
{
	if (!InstigatorActor || !TargetBoss)
	{
		return false;
	}

	UWorld* World = InstigatorActor->GetWorld();
	if (!World)
	{
		return false;
	}

	FTripartiteZenithBalancing Params;
	if (BalanceDataAsset)
	{
		Params = BalanceDataAsset->GetClampedTripartiteZenith();
	}
	else
	{
		Params.BaseDamage = FinisherDamage;
		Params.PoiseDamage = PoiseDamage;
		Params.TimeDilationScale = TimeDilationScale;
		Params.CompanionFatigueCost = 0.35f;
	}

	// 1. Slow motion dilation
	UGameplayStatics::SetGlobalTimeDilation(World, Params.TimeDilationScale);

	// 2. Inflict massive damage to boss
	if (UAshenOath_HealthComponent* BossHealth = TargetBoss->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		BossHealth->ReceiveDamage(Params.BaseDamage, InstigatorActor);
	}

	// 3. Apply poise damage / break
	if (UAshenOath_PoiseComponent* BossPoise = TargetBoss->FindComponentByClass<UAshenOath_PoiseComponent>())
	{
		BossPoise->ApplyPoiseDamage(Params.PoiseDamage);
	}

	// 4. Add fatigue to both companions
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(TEXT("Garrett"), Params.CompanionFatigueCost);
			FatigueSubsystem->AccumulateFatigue(TEXT("Serafina"), Params.CompanionFatigueCost);
		}
	}

	// 5. Modulate Tripartite Zenith dynamic emissives
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(1.0f, 0.85f, 0.2f, 1.0f), 10.0f);
	}

	if (OnTripartiteZenithExecuted.IsBound())
	{
		OnTripartiteZenithExecuted.Broadcast(Params.BaseDamage, Params.PoiseDamage, Params.TimeDilationScale, Params.CompanionFatigueCost);
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenTripartiteSovereignFinisherGASAbility: *** GRAND TRIPARTITE ZENITH FINISHER *** (%.0f Damage | %.0f Poise | %.2fx Dilation | +%.2f Trio Fatigue)!"),
		Params.BaseDamage, Params.PoiseDamage, Params.TimeDilationScale, Params.CompanionFatigueCost);

	return true;
}

void UAshenTripartiteSovereignFinisherGASAbility::ActivateAbility(
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
	AActor* Target = TriggerEventData ? const_cast<AActor*>(TriggerEventData->Target.Get()) : nullptr;
	ExecuteTripartiteFinisher(Owner, Target);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
