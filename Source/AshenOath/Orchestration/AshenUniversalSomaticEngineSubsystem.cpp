// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenUniversalSomaticEngineSubsystem.h"
#include "Engine/World.h"

UAshenUniversalSomaticEngineSubsystem::UAshenUniversalSomaticEngineSubsystem()
{
}

void UAshenUniversalSomaticEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	SalienceBudget = FSalienceBudget();
}

void UAshenUniversalSomaticEngineSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FSomaticState UAshenUniversalSomaticEngineSubsystem::EvaluateSomaticState(
	const FCanonicalSoulStateVector& SoulState,
	const FCanonicalRelationalMatrix& RelationalState,
	const FContextualPressureState& ContextPressure,
	FGuid TransactionId,
	int64 StateVersion)
{
	FSomaticState Result;
	Result.SourceTransactionId = TransactionId;
	Result.SourceStateVersion = StateVersion;

	// 1. Derive Relational Flow (Psi)
	const float ThreatFactor = FMath::Clamp(1.0f - (ContextPressure.ImmediateThreatIntensity * 0.20f), 0.0f, 1.0f);
	const float ProximityWeighted = ThreatFactor * ContextPressure.CompanionProximityFactor * 0.30f;
	const float SupportBonus = ContextPressure.bCompanionSupportPresent ? 0.10f : 0.0f;
	Result.RelationalFlow = FMath::Clamp(
		(RelationalState.TrioResonance * 0.60f) + ProximityWeighted + SupportBonus,
		0.0f, 1.0f);

	// 2. Derive Internal Friction (Phi)
	const float LensDistance = AshenContractUtils::GetLensDistance(SoulState.DominantLens, SoulState.PreviousDominantLens);
	Result.InternalFriction = FMath::Clamp(
		(0.40f * SoulState.IntegrationDebt) +
		(0.30f * SoulState.AccumulatedDysregulation) +
		(0.30f * LensDistance) +
		(0.20f * ContextPressure.ImmediateThreatIntensity) -
		(0.20f * SoulState.Resolve),
		0.0f, 1.0f);

	// 3. Derive Auxiliary Somatic Vectors
	Result.ParasitePressure = FMath::Clamp(
		(0.50f * SoulState.Corruption) +
		(0.30f * Result.InternalFriction) +
		(0.20f * (1.0f - SoulState.Resolve)),
		0.0f, 1.0f);

	Result.WillCapacity = FMath::Clamp(
		(0.60f * SoulState.Resolve) +
		(0.20f * (1.0f - Result.InternalFriction)) +
		(0.20f * Result.RelationalFlow),
		0.0f, 1.0f);

	Result.IsolationPressure = FMath::Clamp(
		(0.60f * (1.0f - Result.RelationalFlow)) +
		(0.40f * (1.0f - ContextPressure.CompanionProximityFactor)),
		0.0f, 1.0f);

	CachedSomaticState = Result;
	OnSomaticStateUpdated.Broadcast(Result);

	return Result;
}

FActionCongruenceResult UAshenUniversalSomaticEngineSubsystem::EvaluateActionCongruence(
	const FCanonicalSoulStateVector& SoulState,
	const FCanonicalRelationalMatrix& RelationalState,
	FGameplayTag IntendedActionTag,
	EOntologicalLens IntendedLens,
	float MemorySeverity,
	FName TargetCompanionName,
	FGuid TransactionId,
	int64 StateVersion)
{
	FActionCongruenceResult Result;
	Result.SourceTransactionId = TransactionId;
	Result.SourceStateVersion = StateVersion;
	Result.IntendedActionTag = IntendedActionTag;
	Result.MemorySeverity = MemorySeverity;

	// Determine Active Companion Trust with fallback to TrioResonance
	float ActiveTrust = RelationalState.TrioResonance;
	if (TargetCompanionName == FName(TEXT("Serafina")))
	{
		ActiveTrust = RelationalState.Trust_Serafina;
	}
	else if (TargetCompanionName == FName(TEXT("Garrett")))
	{
		ActiveTrust = RelationalState.Trust_Garrett;
	}
	Result.ActiveCompanionTrust = ActiveTrust;

	const float LensDistance = AshenContractUtils::GetLensDistance(IntendedLens, SoulState.DominantLens);

	// Formula: w1*D + w2*DeltaL + w3*(1-Tr) + w4*M_severity - w5*R
	Result.ResistanceSomatic = FMath::Clamp(
		(0.30f * SoulState.IntegrationDebt) +
		(0.25f * LensDistance) +
		(0.20f * (1.0f - ActiveTrust)) +
		(0.15f * MemorySeverity) -
		(0.20f * SoulState.Resolve),
		0.0f, 1.0f);

	OnActionCongruenceEvaluated.Broadcast(Result);
	return Result;
}

bool UAshenUniversalSomaticEngineSubsystem::EvaluateSalienceGate(
	const FSomaticState& CurrentState,
	double CurrentTimeSeconds,
	FSomaticExpressionIntent& OutIntent)
{
	const float DFriction  = FMath::Abs(CurrentState.InternalFriction  - SalienceBudget.LastDispatchedFriction);
	const float DFlow      = FMath::Abs(CurrentState.RelationalFlow    - SalienceBudget.LastDispatchedFlow);
	const float DParasite  = FMath::Abs(CurrentState.ParasitePressure  - SalienceBudget.LastDispatchedParasite);
	const float DWill      = FMath::Abs(CurrentState.WillCapacity      - SalienceBudget.LastDispatchedWill);
	const float DIsolation = FMath::Abs(CurrentState.IsolationPressure - SalienceBudget.LastDispatchedIsolation);

	const float MaxDelta = FMath::Max3(DFriction, DFlow, FMath::Max3(DParasite, DWill, DIsolation));

	const bool bCooldownElapsed = (CurrentTimeSeconds - SalienceBudget.LastExpressionTimestamp) >= SalienceBudget.MinCooldownSeconds;
	const bool bCriticalBypass  = (MaxDelta >= SalienceBudget.CriticalBypassThreshold);
	const bool bThresholdExceeded = (MaxDelta >= SalienceBudget.SalienceThreshold);

	if (bCriticalBypass || (bThresholdExceeded && bCooldownElapsed))
	{
		SalienceBudget.LastDispatchedFriction  = CurrentState.InternalFriction;
		SalienceBudget.LastDispatchedFlow      = CurrentState.RelationalFlow;
		SalienceBudget.LastDispatchedParasite  = CurrentState.ParasitePressure;
		SalienceBudget.LastDispatchedWill      = CurrentState.WillCapacity;
		SalienceBudget.LastDispatchedIsolation = CurrentState.IsolationPressure;
		SalienceBudget.LastExpressionTimestamp = CurrentTimeSeconds;

		OutIntent.SourceTransactionId = CurrentState.SourceTransactionId;
		OutIntent.SourceStateVersion = CurrentState.SourceStateVersion;
		OutIntent.ActiveResistanceSource = ETriggerResistanceSource::AmbientSomatic;
		OutIntent.InputResistanceIntent = FMath::Clamp(CurrentState.InternalFriction * 0.35f, 0.0f, 1.0f);
		OutIntent.AudioIntrusionIntent = CurrentState.ParasitePressure;
		OutIntent.HapticTremorIntent = FMath::Clamp(CurrentState.InternalFriction * 0.70f + CurrentState.ParasitePressure * 0.30f, 0.0f, 1.0f);
		OutIntent.VisualInstabilityIntent = CurrentState.InternalFriction;
		OutIntent.JournalDegradationIntent = FMath::Clamp(CurrentState.InternalFriction * 0.60f + CurrentState.IsolationPressure * 0.40f, 0.0f, 1.0f);
		OutIntent.CompanionSupportExpression = CurrentState.RelationalFlow;

		CachedExpressionIntent = OutIntent;
		OnExpressionIntentDispatched.Broadcast(OutIntent);
		return true;
	}

	return false;
}

float UAshenUniversalSomaticEngineSubsystem::CalculateEffectiveStaminaRegenScalar(float InternalFriction, float BaseRegenScalar) const
{
	return FMath::Clamp(BaseRegenScalar * (1.0f - (0.40f * FMath::Clamp(InternalFriction, 0.0f, 1.0f))), 0.10f, 2.0f);
}

float UAshenUniversalSomaticEngineSubsystem::CalculateNetSomaticExhaustionPenalty(float InternalFriction, float RelationalFlow) const
{
	const float ClampedPhi = FMath::Clamp(InternalFriction, 0.0f, 1.0f);
	const float ClampedPsi = FMath::Clamp(RelationalFlow, 0.0f, 1.0f);
	return ClampedPhi * (1.0f - (0.50f * ClampedPsi));
}
