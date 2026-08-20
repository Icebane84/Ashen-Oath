// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenQualitativeInterpretationEngine.h"

UAshenQualitativeInterpretationEngine::UAshenQualitativeInterpretationEngine()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenQualitativeInterpretationEngine::BeginPlay()
{
	Super::BeginPlay();
}

FAshenQualitativeMindState UAshenQualitativeInterpretationEngine::InterpretSoulStateVector(float IntegrationDebt, float Resolve, float Isolation, float GarrettTrust)
{
	FAshenQualitativeMindState MindState;

	if (IntegrationDebt >= 0.70f)
	{
		MindState.MindStateText = FText::FromString(TEXT("Mind State: Fracturing (High Static Noise)"));
	}
	else
	{
		MindState.MindStateText = FText::FromString(TEXT("Mind State: Integrated & Clear"));
	}

	if (Resolve >= 0.70f)
	{
		MindState.CharacterStanceText = FText::FromString(TEXT("Character Stance: Unshakeable / Resolute"));
	}
	else
	{
		MindState.CharacterStanceText = FText::FromString(TEXT("Character Stance: Hesitant / Shaken"));
	}

	if (Isolation <= 0.30f)
	{
		MindState.RelationalAnchorText = FText::FromString(TEXT("Relational Anchor: Connected"));
	}
	else
	{
		MindState.RelationalAnchorText = FText::FromString(TEXT("Relational Anchor: Isolated"));
	}

	if (GarrettTrust >= 0.80f)
	{
		MindState.TacticalSynergyText = FText::FromString(TEXT("Tactical Synergy: Synchronized / In Lockstep"));
	}
	else
	{
		MindState.TacticalSynergyText = FText::FromString(TEXT("Tactical Synergy: Friction / Guarded"));
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenQualitativeInterpretationEngine: Interpreted raw C++ floats into qualitative mind state narrative truth."));
	return MindState;
}
