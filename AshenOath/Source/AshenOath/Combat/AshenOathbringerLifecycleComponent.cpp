// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerLifecycleComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenOathbringerLifecycleComponent::UAshenOathbringerLifecycleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentLifecycle = EOathbringerLifecycleState::Dormant;
	EffectiveMass = 120.0f;
	ForwardPullImpulse = 0.0f;
}

void UAshenOathbringerLifecycleComponent::BeginPlay()
{
	Super::BeginPlay();
	EvaluateWeaponLifecycle();
}

EOathbringerLifecycleState UAshenOathbringerLifecycleComponent::EvaluateWeaponLifecycle()
{
	EOathbringerLifecycleState NewLifecycle = EOathbringerLifecycleState::Dormant;
	EffectiveMass = 120.0f;
	ForwardPullImpulse = 0.0f;
	FLinearColor EmissiveColor = FLinearColor(0.1f, 0.1f, 0.1f, 1.0f); // Matte iron

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FSoulStateVector State = Publisher->GetSoulState();
		if (State.Corruption >= 0.70f)
		{
			// Autonomous: Shadow pull
			NewLifecycle = EOathbringerLifecycleState::Autonomous;
			EffectiveMass = 0.0f;
			ForwardPullImpulse = 400.0f; // +400 uu/s forward impulse pull
			EmissiveColor = FLinearColor(0.85f, 0.05f, 0.05f, 1.0f); // Crimson Nightsteel
		}
		else if (State.Resolve >= 0.70f)
		{
			// Predictive: Flow State
			NewLifecycle = EOathbringerLifecycleState::Predictive;
			EffectiveMass = 45.0f; // Lightweight flow mass
			ForwardPullImpulse = 0.0f;
			EmissiveColor = FLinearColor(0.40f, 0.75f, 1.0f, 1.0f); // Azure / Silver White Flame
		}
	}

	if (CurrentLifecycle != NewLifecycle)
	{
		CurrentLifecycle = NewLifecycle;
		OnLifecycleChanged.Broadcast(CurrentLifecycle, EffectiveMass, EmissiveColor);
		UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerLifecycleComponent: Lifecycle transitioned to [%d] (Mass: %.1fkg, Pull: %.1fuu/s)."),
			(int32)CurrentLifecycle, EffectiveMass, ForwardPullImpulse);
	}

	return CurrentLifecycle;
}

bool UAshenOathbringerLifecycleComponent::InscribeMemoryEchoToGuardSocket(
	EOathbringerMartialStance Guard,
	FName MemoryEchoID)
{
	if (MemoryEchoID.IsNone()) return false;

	GuardSocketMap.Add(Guard, MemoryEchoID);
	OnGuardSocketInscribed.Broadcast(Guard, MemoryEchoID);

	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerLifecycleComponent: Inscribed Echo '%s' to Guard Socket [%d]."),
		*MemoryEchoID.ToString(), (int32)Guard);

	return true;
}

FLinearColor UAshenOathbringerLifecycleComponent::GetGuardSocketEmissiveColor(EOathbringerMartialStance Guard) const
{
	switch (Guard)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		// Charcoal Gold
		return FLinearColor(0.85f, 0.65f, 0.15f, 1.0f);

	case EOathbringerMartialStance::Pflug_LowPlow:
		// Copper Amber
		return FLinearColor(0.80f, 0.40f, 0.10f, 1.0f);

	case EOathbringerMartialStance::Ochs_CrownGuard:
		// Silver Blue (528 Hz White Flame)
		return FLinearColor(0.35f, 0.70f, 1.0f, 1.0f);

	case EOathbringerMartialStance::Mordhau_HalfSword:
		// Crimson Ash
		return FLinearColor(0.70f, 0.10f, 0.15f, 1.0f);

	default:
		return FLinearColor::White;
	}
}

FName UAshenOathbringerLifecycleComponent::GetSocketInscribedEcho(EOathbringerMartialStance Guard) const
{
	if (const FName* Found = GuardSocketMap.Find(Guard))
	{
		return *Found;
	}
	return NAME_None;
}

UAshenSoulPublisher* UAshenOathbringerLifecycleComponent::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
