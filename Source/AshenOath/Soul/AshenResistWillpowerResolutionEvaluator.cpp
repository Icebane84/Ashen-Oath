// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 826: Ashen Resist Willpower Resolution Evaluator

#include "AshenResistWillpowerResolutionEvaluator.h"

void UAshenResistWillpowerResolutionEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalResistancesExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenResistWillpowerResolutionEvaluator: Initialized — Resist Willpower Resolution Evaluator ONLINE."));
}

void UAshenResistWillpowerResolutionEvaluator::ExecuteResistWillpowerResolution()
{
	TotalResistancesExecuted++;
	const FName StateTag = FName(TEXT("State.Willpower.Unbroken"));

	OnResistExecuted.Broadcast(StateTag, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenResistWillpowerResolutionEvaluator: RESISTED DEVIL'S BARGAIN -> State: '%s' | Glass Shatter Silver Dust VFX Active | Full Stamina Restored | Flow State Initiated."),
		*StateTag.ToString());
}
