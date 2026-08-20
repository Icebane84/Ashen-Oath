// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 623: Ashen Plausible Destructiveness Evaluator

#include "AshenPlausibleDestructivenessEvaluator.h"

void UAshenPlausibleDestructivenessEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenPlausibleDestructivenessEvaluator: Initialized — Plausible Destructiveness Evaluator ONLINE."));
}

FString UAshenPlausibleDestructivenessEvaluator::SelectMostDestructivePlausibleWhisper(FName MemoryID, float UnresolvedTraumaWeight)
{
	const float Plausibility = FMath::Clamp(UnresolvedTraumaWeight * 0.85f, 0.1f, 1.0f);
	const FString SelectedWhisper = (Plausibility > 0.6f)
		? TEXT("Garrett only repaired your blade so you would draw blood for him.")
		: TEXT("Serafina hides her empathic exhaustion because she pities your weakness.");

	OnDestructivenessEvaluated.Broadcast(MemoryID, SelectedWhisper, Plausibility);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPlausibleDestructivenessEvaluator: PLAUSIBLE DESTRUCTIVENESS EVALUATED -> Memory '%s' | Plausibility: %.2f | Whisper: '%s'."),
		*MemoryID.ToString(), Plausibility, *SelectedWhisper);

	return SelectedWhisper;
}
