// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenRelationalEcologySubsystem.h"
#include "Engine/World.h"

UAshenRelationalEcologySubsystem::UAshenRelationalEcologySubsystem()
{
}

void UAshenRelationalEcologySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CompanionRepairMatrices.Add(FName(TEXT("Garrett")), FAshenRepairMatrix());
	CompanionRepairMatrices.Add(FName(TEXT("Serafina")), FAshenRepairMatrix());
}

void UAshenRelationalEcologySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

float UAshenRelationalEcologySubsystem::CalculateFaithThreshold(float ImmediateThreat, float ActiveRepairVelocity) const
{
	// Formula: Clamp(0.50*Threat - 0.40*RepairVelocity, 0.15, 0.85)
	const float RawThreshold = (ImmediateThreat * 0.50f) - (ActiveRepairVelocity * 0.40f);
	return FMath::Clamp(RawThreshold, 0.15f, 0.85f);
}

FAshenCostlyPresenceIntent UAshenRelationalEcologySubsystem::EvaluateCostlyPresenceIntent(
	FName CompanionName,
	float CompanionTrust,
	float ImmediateThreat,
	const FAshenRepairMatrix& RepairHistory)
{
	FAshenCostlyPresenceIntent Intent;
	Intent.IntentId = FGuid::NewGuid();
	Intent.CompanionName = CompanionName;
	Intent.CompanionTrustSnapshot = CompanionTrust;
	Intent.ComputedFaithThreshold = CalculateFaithThreshold(ImmediateThreat, RepairHistory.ActiveRepairVelocity);

	// Approval check: Companion trust must meet or exceed the faith threshold
	Intent.bInterventionApproved = (CompanionTrust >= Intent.ComputedFaithThreshold);

	if (CompanionName == FName(TEXT("Garrett")))
	{
		Intent.InterventionType = ECompanionInterventionType::CostlyPresenceInterception;
	}
	else if (CompanionName == FName(TEXT("Serafina")))
	{
		Intent.InterventionType = (ImmediateThreat >= 0.70f) ? ECompanionInterventionType::SanctuaryCircleCast : ECompanionInterventionType::EmpathicTransference;
	}

	return Intent;
}

void UAshenRelationalEcologySubsystem::AddMultiAuthorEntry(
	EAuthorIdentity Author,
	const FText& Text,
	FName MemorySiteId,
	float StainOpacity)
{
	FAshenMultiAuthorMarginEntry NewEntry;
	NewEntry.EntryId = FGuid::NewGuid();
	NewEntry.Author = Author;
	NewEntry.EntryText = Text;
	NewEntry.AttachedMemorySiteId = MemorySiteId;
	NewEntry.StainOpacity = FMath::Clamp(StainOpacity, 0.10f, 1.0f);
	NewEntry.TimestampSeconds = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;

	JournalEntries.Add(NewEntry);
	OnMultiAuthorEntryAdded.Broadcast(NewEntry);
}

void UAshenRelationalEcologySubsystem::UpdateRepairMatrix(FName CompanionName, const FAshenRepairMatrix& NewMatrix)
{
	CompanionRepairMatrices.FindOrAdd(CompanionName) = NewMatrix;
	OnRelationalRuptureChanged.Broadcast(CompanionName, NewMatrix.CurrentRuptureState);
}

FAshenRepairMatrix UAshenRelationalEcologySubsystem::GetRepairMatrix(FName CompanionName) const
{
	if (const FAshenRepairMatrix* Found = CompanionRepairMatrices.Find(CompanionName))
	{
		return *Found;
	}
	return FAshenRepairMatrix();
}
