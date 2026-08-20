// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenCompanionMarginaliaEvaluatorComponent.h"
#include "Companions/AshenMarginaliaSpatialLayoutEngine.h"
#include "Companions/AshenDeterministicMarginaliaFallbackProvider.h"
#include "Companions/AshenMarginaliaProvenanceValidator.h"
#include "Soul/AshenSoulStateVector.h"

UAshenCompanionMarginaliaEvaluatorComponent::UAshenCompanionMarginaliaEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionMarginaliaEvaluatorComponent::BeginPlay()
{
	Super::BeginPlay();

	LayoutEngine = NewObject<UAshenMarginaliaSpatialLayoutEngine>(this);
	FallbackProvider = NewObject<UAshenDeterministicMarginaliaFallbackProvider>(this);
	ProvenanceValidator = NewObject<UAshenMarginaliaProvenanceValidator>(this);
}

TArray<FMarginaliaEntry> UAshenCompanionMarginaliaEvaluatorComponent::EvaluateCampfireMarginalia(
	const FCanonicalSoulStateVector& CurrentSoulState,
	const TArray<FString>& ActiveImprints)
{
	TArray<FMarginaliaEntry> RawEntries;

	const FString PrimaryMemory = ActiveImprints.Num() > 0 ? ActiveImprints[0] : TEXT("");

	if (FallbackProvider)
	{
		RawEntries = FallbackProvider->GenerateDeterministicEntries(CurrentSoulState, PrimaryMemory);
	}

	TArray<FMarginaliaEntry> ValidatedEntries;
	if (ProvenanceValidator)
	{
		ProvenanceValidator->ValidateEntries(RawEntries, ActiveImprints, ValidatedEntries);
	}
	else
	{
		ValidatedEntries = RawEntries;
	}

	TArray<FMarginaliaEntry> FinalLayoutEntries;
	if (LayoutEngine)
	{
		FinalLayoutEntries = LayoutEngine->ResolveSpatialCollisions(ValidatedEntries);
	}
	else
	{
		FinalLayoutEntries = ValidatedEntries;
	}

	OnMarginaliaBatchGenerated.Broadcast(FinalLayoutEntries);
	return FinalLayoutEntries;
}

void UAshenCompanionMarginaliaEvaluatorComponent::EvaluateMarginalia(const FSoulStateVector& State)
{
	FCanonicalSoulStateVector CanonicalState;
	CanonicalState.DominantLens = (State.PrimaryLens == EInterpretiveLens::Grace) ? EOntologicalLens::Grace : EOntologicalLens::Defiance;
	CanonicalState.AccumulatedDysregulation = State.IntegrationDebt;

	TArray<FString> MockImprints;
	MockImprints.Add(TEXT("mem_default_001"));

	const TArray<FMarginaliaEntry> Entries = EvaluateCampfireMarginalia(CanonicalState, MockImprints);
	for (const FMarginaliaEntry& Entry : Entries)
	{
		if (Entry.Author == EMarginaliaAuthor::Garrett)
		{
			CachedGarrettMarginalia = Entry.InscriptionText;
		}
		else if (Entry.Author == EMarginaliaAuthor::Serafina)
		{
			CachedSerafinaMarginalia = Entry.InscriptionText;
		}
	}
}
