// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenCanonicalStateRegistryComponent.h"

UAshenCanonicalStateRegistryComponent::UAshenCanonicalStateRegistryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentSoulState = FCanonicalSoulStateVector();
	CurrentRelationalMatrix = FCanonicalRelationalMatrix();
}

void UAshenCanonicalStateRegistryComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCanonicalStateRegistryComponent::ValidateInvariants(
	const FCanonicalSoulStateVector& ProposedSoul,
	const FCanonicalRelationalMatrix& ProposedRelational,
	const FGameplayTagContainer& TransactionTags,
	bool bIsDebtReduction) const
{
	// Invariant 1: Range checks for all scalar floats [0.0, 1.0]
	if (ProposedSoul.IntegrationDebt < 0.0f || ProposedSoul.IntegrationDebt > 1.0f ||
		ProposedSoul.AccumulatedDysregulation < 0.0f || ProposedSoul.AccumulatedDysregulation > 1.0f ||
		ProposedSoul.Resolve < 0.0f || ProposedSoul.Resolve > 1.0f ||
		ProposedSoul.Corruption < 0.0f || ProposedSoul.Corruption > 1.0f ||
		ProposedRelational.Trust_Serafina < 0.0f || ProposedRelational.Trust_Serafina > 1.0f ||
		ProposedRelational.Burnout_Serafina < 0.0f || ProposedRelational.Burnout_Serafina > 1.0f ||
		ProposedRelational.Trust_Garrett < 0.0f || ProposedRelational.Trust_Garrett > 1.0f ||
		ProposedRelational.Fatigue_Garrett < 0.0f || ProposedRelational.Fatigue_Garrett > 1.0f ||
		ProposedRelational.TrioResonance < 0.0f || ProposedRelational.TrioResonance > 1.0f)
	{
		return false;
	}

	// Invariant 2: Debt reduction REQUIRES a Resolution.* tag
	if (bIsDebtReduction)
	{
		bool bHasResolutionTag = false;
		for (const FGameplayTag& Tag : TransactionTags)
		{
			if (Tag.ToString().StartsWith(TEXT("Resolution.")))
			{
				bHasResolutionTag = true;
				break;
			}
		}
		if (!bHasResolutionTag)
		{
			return false;
		}
	}

	// Invariant 4: Bifurcation mutex (Corruption up and Resolve up in same commit forbidden without special tag)
	const bool bCorruptionRose = ProposedSoul.Corruption > CurrentSoulState.Corruption;
	const bool bResolveRose = ProposedSoul.Resolve > CurrentSoulState.Resolve;
	if (bCorruptionRose && bResolveRose)
	{
		if (!TransactionTags.HasTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Resolution.BifurcatedWill")), false)))
		{
			return false;
		}
	}

	// Invariant 5: TrioResonance bounding
	const float MinTrust = FMath::Min(ProposedRelational.Trust_Serafina, ProposedRelational.Trust_Garrett);
	const float MaxTrust = FMath::Max(ProposedRelational.Trust_Serafina, ProposedRelational.Trust_Garrett);
	if (ProposedRelational.TrioResonance < (MinTrust - 0.20f) || ProposedRelational.TrioResonance > (MaxTrust + 0.20f))
	{
		return false;
	}

	return true;
}

bool UAshenCanonicalStateRegistryComponent::CommitCompilationResult(
	const FCompilationResult& CompilationResult,
	FGuid& OutTransactionId)
{
	FCanonicalSoulStateVector ProposedSoul = CurrentSoulState;
	ProposedSoul.IntegrationDebt = CompilationResult.IntegrationDebtAfter;
	ProposedSoul.Resolve = FMath::Clamp(CurrentSoulState.Resolve + CompilationResult.ResolveDelta, 0.0f, 1.0f);
	ProposedSoul.Corruption = FMath::Clamp(CurrentSoulState.Corruption + CompilationResult.CorruptionDelta, 0.0f, 1.0f);
	ProposedSoul.PreviousDominantLens = CurrentSoulState.DominantLens;
	ProposedSoul.DominantLens = CompilationResult.SelectedLens;
	ProposedSoul.StateVersion = CurrentSoulState.StateVersion + 1; // Invariant 3

	FCanonicalRelationalMatrix ProposedRelational = CurrentRelationalMatrix;
	ProposedRelational.Trust_Garrett = FMath::Clamp(CurrentRelationalMatrix.Trust_Garrett + CompilationResult.TrustGarrettDelta, 0.0f, 1.0f);
	ProposedRelational.Trust_Serafina = FMath::Clamp(CurrentRelationalMatrix.Trust_Serafina + CompilationResult.TrustSerafinaDelta, 0.0f, 1.0f);
	ProposedRelational.TrioResonance = FMath::Clamp(CurrentRelationalMatrix.TrioResonance + CompilationResult.TrioResonanceDelta, 0.0f, 1.0f);

	const bool bIsDebtReduction = CompilationResult.IntegrationDebtAfter < CompilationResult.IntegrationDebtBefore;

	if (!ValidateInvariants(ProposedSoul, ProposedRelational, CompilationResult.ResolutionTags, bIsDebtReduction))
	{
		return false;
	}

	OutTransactionId = FGuid::NewGuid();
	CommittedTransactionHistory.Add(OutTransactionId);

	CurrentSoulState = ProposedSoul;
	CurrentRelationalMatrix = ProposedRelational;

	OnCanonicalStateCommitted.Broadcast(CurrentSoulState, CurrentRelationalMatrix, CurrentSoulState.StateVersion, OutTransactionId);
	return true;
}

bool UAshenCanonicalStateRegistryComponent::CommitDirectStateMutation(
	const FCanonicalSoulStateVector& NewSoulState,
	const FCanonicalRelationalMatrix& NewRelationalMatrix,
	const FGameplayTagContainer& AuthorizationTags,
	FGuid& OutTransactionId)
{
	FCanonicalSoulStateVector ValidatedSoul = NewSoulState;
	ValidatedSoul.StateVersion = CurrentSoulState.StateVersion + 1; // Invariant 3

	const bool bIsDebtReduction = ValidatedSoul.IntegrationDebt < CurrentSoulState.IntegrationDebt;

	if (!ValidateInvariants(ValidatedSoul, NewRelationalMatrix, AuthorizationTags, bIsDebtReduction))
	{
		return false;
	}

	OutTransactionId = FGuid::NewGuid();
	CommittedTransactionHistory.Add(OutTransactionId);

	CurrentSoulState = ValidatedSoul;
	CurrentRelationalMatrix = NewRelationalMatrix;

	OnCanonicalStateCommitted.Broadcast(CurrentSoulState, CurrentRelationalMatrix, CurrentSoulState.StateVersion, OutTransactionId);
	return true;
}
