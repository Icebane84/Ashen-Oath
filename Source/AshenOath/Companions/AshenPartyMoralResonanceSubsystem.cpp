// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 528: Ashen Party Moral Resonance Subsystem

#include "AshenPartyMoralResonanceSubsystem.h"

void UAshenPartyMoralResonanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CalculatedPartyMoraleMultiplier = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenPartyMoralResonanceSubsystem: Initialized — Party Moral Resonance Engine ONLINE."));
}

void UAshenPartyMoralResonanceSubsystem::RegisterMoralChoiceResolution(FName MoralAlignmentTag, float AlignmentDelta)
{
	if (MoralAlignmentTag.IsNone()) return;

	CalculatedPartyMoraleMultiplier = FMath::Clamp(CalculatedPartyMoraleMultiplier + AlignmentDelta, 0.5f, 2.0f);
	OnMoralAlignmentShifted.Broadcast(MoralAlignmentTag, CalculatedPartyMoraleMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPartyMoralResonanceSubsystem: MORAL CHOICE RESOLVED -> '%s' (Party Morale Multiplier: %.2fx)."),
		*MoralAlignmentTag.ToString(), CalculatedPartyMoraleMultiplier);
}
