// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenCampfireReflectionSubsystem.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/GameInstance.h"

void UAshenCampfireReflectionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentPhase = ECampfireReflectionPhase::Completed;
	PendingFragments.Empty();

	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireReflectionSubsystem: Initialized Campfire Sanctuary Subsystem."));
}

void UAshenCampfireReflectionSubsystem::BeginCampfireRest()
{
	SetReflectionPhase(ECampfireReflectionPhase::Resting);
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireReflectionSubsystem: Kaelen sits at the campfire sanctuary. Ambient tension dissipates."));
}

void UAshenCampfireReflectionSubsystem::SetReflectionPhase(ECampfireReflectionPhase NewPhase)
{
	if (CurrentPhase != NewPhase)
	{
		CurrentPhase = NewPhase;
		if (OnCampfirePhaseChanged.IsBound())
		{
			OnCampfirePhaseChanged.Broadcast(CurrentPhase);
		}
	}
}

void UAshenCampfireReflectionSubsystem::QueueMemoryFragment(const FCampfireMemoryFragment& Fragment)
{
	PendingFragments.Add(Fragment);
}

FCampfireIntegrationResult UAshenCampfireReflectionSubsystem::IntegrateBufferedMemories(EInterpretiveLens ChosenLens)
{
	FCampfireIntegrationResult Result;
	Result.AppliedLens = ChosenLens;

	UGameInstance* GI = GetGameInstance();
	if (!GI)
	{
		return Result;
	}

	UAshenSoulPublisher* SoulPublisher = GI->GetSubsystem<UAshenSoulPublisher>();
	if (!SoulPublisher)
	{
		return Result;
	}

	const FSoulStateVector CurrentState = SoulPublisher->GetSoulState();
	Result.DebtCleared = CurrentState.IntegrationDebt;

	// Calculate accumulated raw weight
	float TotalTraumaWeight = 0.15f; // Baseline processing weight
	for (const FCampfireMemoryFragment& Frag : PendingFragments)
	{
		TotalTraumaWeight += Frag.RawTraumaWeight;
	}

	float ResolveDelta = 0.0f;
	float CorruptionDelta = 0.0f;
	float GarrettDelta = 0.0f;
	float SerafinaDelta = 0.0f;

	switch (ChosenLens)
	{
	case EInterpretiveLens::Accountability:
		// Accountability: Bearing responsibility strengthens resolve, stabilizes posture, and sharpens edge
		ResolveDelta = FMath::Clamp(TotalTraumaWeight * 0.40f, 0.05f, 0.35f);
		CorruptionDelta = -0.05f; // Slight purification
		Result.ResolveGained = ResolveDelta;
		break;

	case EInterpretiveLens::Grace:
		// Grace/Compassion: Forgiveness heals fractures and builds deep companion trust
		GarrettDelta = FMath::Clamp(TotalTraumaWeight * 0.30f, 0.05f, 0.25f);
		SerafinaDelta = FMath::Clamp(TotalTraumaWeight * 0.30f, 0.05f, 0.25f);
		ResolveDelta = 0.05f;
		Result.TrustGained = (GarrettDelta + SerafinaDelta) * 0.5f;
		break;

	case EInterpretiveLens::Nihilism:
		// Nihilism/Spite: Cold pragmatism embraces corruption for devastating void power
		CorruptionDelta = FMath::Clamp(TotalTraumaWeight * 0.45f, 0.10f, 0.40f);
		ResolveDelta = -0.05f;
		Result.CorruptionGained = CorruptionDelta;
		break;

	case EInterpretiveLens::Penance:
		// Penance: Self-punishing martyrdom locks in heavy poise armor at the expense of fragility
		ResolveDelta = 0.10f;
		CorruptionDelta = 0.05f;
		Result.ResolveGained = 0.10f;
		break;
	}

	// Construct updated soul state with DEBT CLEARED (Debt -> 0.0)
	FSoulStateVector UpdatedState = CurrentState;
	UpdatedState.Resolve = FMath::Clamp(CurrentState.Resolve + ResolveDelta, 0.0f, 1.0f);
	UpdatedState.Corruption = FMath::Clamp(CurrentState.Corruption + CorruptionDelta, 0.0f, 1.0f);
	UpdatedState.IntegrationDebt = 0.0f; // Zero Debt Invariant
	UpdatedState.GarrettTrust = FMath::Clamp(CurrentState.GarrettTrust + GarrettDelta, 0.0f, 1.0f);
	UpdatedState.SerafinaTrust = FMath::Clamp(CurrentState.SerafinaTrust + SerafinaDelta, 0.0f, 1.0f);
	UpdatedState.PrimaryLens = ChosenLens;

	// Commit atomically to SSoT Publisher
	SoulPublisher->CommitStateDirect(UpdatedState);

	// Derive resulting metallurgy tier
	Result.ResultingMetallurgyTier = DeriveTargetMetallurgyTier(UpdatedState.Resolve, UpdatedState.Corruption, UpdatedState.IntegrationDebt);
	Result.ResultingWeaponMass = UAshenSoulPublisher::CalculateGameplayEffectiveMass(UpdatedState.IntegrationDebt, UpdatedState.Corruption, UpdatedState.Resolve);

	// Clear memory fragment buffer
	PendingFragments.Empty();

	// Advance reflection state machine
	SetReflectionPhase(ECampfireReflectionPhase::MorphingBlade);

	if (OnCampfireMemoryIntegrated.IsBound())
	{
		OnCampfireMemoryIntegrated.Broadcast(Result);
	}

	SetReflectionPhase(ECampfireReflectionPhase::Completed);
	return Result;
}

EOathbringerMetallurgicalTier UAshenCampfireReflectionSubsystem::DeriveTargetMetallurgyTier(float Resolve, float Corruption, float Debt) const
{
	// Tier 5: Cold Monolith (Mastery Apotheosis: Resolve >= 0.90 or Corruption >= 0.90 with 0 Debt)
	if ((Resolve >= 0.90f || Corruption >= 0.90f) && Debt <= 0.05f)
	{
		return EOathbringerMetallurgicalTier::ColdMonolith;
	}

	// Tier 4: Devouring Nightsteel (High Corruption >= 0.60)
	if (Corruption >= 0.60f)
	{
		return EOathbringerMetallurgicalTier::DevouringNightsteel;
	}

	// Tier 3: The Scribed Vow (High Resolve >= 0.60)
	if (Resolve >= 0.60f)
	{
		return EOathbringerMetallurgicalTier::ScribedVow;
	}

	// Tier 2: Honed Damascus (Balanced, low debt)
	if (Debt <= 0.20f)
	{
		return EOathbringerMetallurgicalTier::HonedDamascus;
	}

	// Tier 1: Burdened Iron (High debt or raw unrefined state)
	return EOathbringerMetallurgicalTier::BurdenedIron;
}
