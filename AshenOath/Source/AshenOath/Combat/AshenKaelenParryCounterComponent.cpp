// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 173: Ashen Kaelen Parry Counter Component

#include "AshenKaelenParryCounterComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

UAshenKaelenParryCounterComponent::UAshenKaelenParryCounterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ParryWindowDuration   = 0.25f;
	CooldownDuration      = 1.5f;
	MaxConsecutiveParries = 3;
	RiposteDamage         = 160.0f;
	RipostePoiseDamage    = 70.0f;
	bParryWindowOpen      = false;
	bOnCooldown           = false;
	ConsecutiveParryCount = 0;
}

void UAshenKaelenParryCounterComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenKaelenParryCounterComponent::OpenParryWindow()
{
	if (bOnCooldown)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenKaelenParryCounterComponent: Parry on cooldown — cannot open window."));
		return;
	}
	if (bParryWindowOpen) return;

	bParryWindowOpen = true;
	OnParryWindowOpened.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("UAshenKaelenParryCounterComponent: Parry window OPENED (%.2fs)."), ParryWindowDuration);

	GetWorld()->GetTimerManager().SetTimer(
		ParryWindowTimer,
		this,
		&UAshenKaelenParryCounterComponent::CloseParryWindow,
		ParryWindowDuration,
		false
	);
}

bool UAshenKaelenParryCounterComponent::TryParryIncomingAttack(AActor* Attacker)
{
	if (!bParryWindowOpen || !Attacker) return false;

	// Successful parry — close window, apply riposte
	GetWorld()->GetTimerManager().ClearTimer(ParryWindowTimer);
	bParryWindowOpen = false;
	ConsecutiveParryCount++;

	// Apply riposte damage to attacker
	UAshenOath_HealthComponent* HealthComp = Attacker->FindComponentByClass<UAshenOath_HealthComponent>();
	if (HealthComp)
	{
		HealthComp->ReceiveDamage(RiposteDamage, GetOwner());
	}

	UAshenOath_PoiseComponent* PoiseComp = Attacker->FindComponentByClass<UAshenOath_PoiseComponent>();
	if (PoiseComp)
	{
		PoiseComp->ApplyPoiseDamage(RipostePoiseDamage);
	}

	OnParrySuccess.Broadcast(Attacker);
	UE_LOG(LogTemp, Warning,
		TEXT("UAshenKaelenParryCounterComponent: PARRY SUCCESS vs '%s' — %.0f Physical + %.0f Poise riposte (chain %d/%d)."),
		*Attacker->GetName(), RiposteDamage, RipostePoiseDamage, ConsecutiveParryCount, MaxConsecutiveParries);

	// Trigger cooldown if chain is maxed
	if (ConsecutiveParryCount >= MaxConsecutiveParries)
	{
		bOnCooldown = true;
		ConsecutiveParryCount = 0;
		UE_LOG(LogTemp, Warning, TEXT("UAshenKaelenParryCounterComponent: Max parry chain reached — %.1fs cooldown started."), CooldownDuration);
		GetWorld()->GetTimerManager().SetTimer(CooldownTimer, this, &UAshenKaelenParryCounterComponent::EndCooldown, CooldownDuration, false);
	}

	return true;
}

void UAshenKaelenParryCounterComponent::CloseParryWindow()
{
	bParryWindowOpen = false;
	OnParryWindowClosed.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("UAshenKaelenParryCounterComponent: Parry window expired — missed."));
}

void UAshenKaelenParryCounterComponent::EndCooldown()
{
	bOnCooldown = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenKaelenParryCounterComponent: Cooldown ended — parry available."));
}
