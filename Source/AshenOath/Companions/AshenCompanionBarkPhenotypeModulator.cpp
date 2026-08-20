// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionBarkPhenotypeModulator.h"

UAshenCompanionBarkPhenotypeModulator::UAshenCompanionBarkPhenotypeModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FName UAshenCompanionBarkPhenotypeModulator::SelectBarkTag(const FBehavioralProfile& Profile, FName BaseTag)
{
	FString Suffix = TEXT("_Steady");
	if (Profile.Stance == EStanceProfile::Hunched_Guarded)
	{
		Suffix = TEXT("_Guarded");
	}
	else if (Profile.Stance == EStanceProfile::Upright_Grounded)
	{
		Suffix = TEXT("_Grounded");
	}

	FName FinalTag = FName(*(BaseTag.ToString() + Suffix));
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionBarkPhenotypeModulator: Bark tag modulated to %s"), *FinalTag.ToString());
	return FinalTag;
}
