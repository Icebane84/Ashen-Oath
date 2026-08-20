// AshenVigilRegistry.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenVigilRegistry.h"

DEFINE_LOG_CATEGORY(LogAshenVigil);

void UAshenVigilRegistry::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogAshenVigil, Log, TEXT("UAshenVigilRegistry initialized."));

	// Pre-populate default campaign Vigils so challenge log is active out-of-the-box
	RegisterVigil(
		"Vigil_Shadowfen",
		FText::FromString("Vigil of the Shadowfen"),
		FText::FromString("Traverse the Shadowfen and endure 3 Null Zone corruption cycles."),
		3,
		250.0f
	);

	RegisterVigil(
		"Vigil_SilentSpire",
		FText::FromString("Vigil of the Silent Spire"),
		FText::FromString("Keep your oath to Garrett during the Silent Spire aftermath."),
		2,
		300.0f
	);
}


bool UAshenVigilRegistry::RegisterVigil(FName VigilID, FText Title, FText Description, int32 TotalStages, float RewardAsh)
{
	if (VigilID.IsNone()) return false;

	for (const FVigilRecord& Existing : Vigils)
	{
		if (Existing.VigilID == VigilID) return false;
	}

	FVigilRecord NewVigil;
	NewVigil.VigilID = VigilID;
	NewVigil.VigilTitle = Title;
	NewVigil.Description = Description;
	NewVigil.TotalStages = FMath::Max(1, TotalStages);
	NewVigil.RewardAsh = RewardAsh;

	Vigils.Add(NewVigil);
	UE_LOG(LogAshenVigil, Log, TEXT("RegisterVigil: Registered '%s' (%d stages)"), *VigilID.ToString(), TotalStages);
	return true;
}

bool UAshenVigilRegistry::ProgressVigil(FName VigilID)
{
	FVigilRecord* Found = Vigils.FindByPredicate([VigilID](const FVigilRecord& Rec) { return Rec.VigilID == VigilID; });
	if (!Found || Found->bCompleted)
	{
		return false;
	}

	Found->CurrentStage++;
	UE_LOG(LogAshenVigil, Log, TEXT("ProgressVigil: '%s' advanced to stage %d/%d"),
		*VigilID.ToString(), Found->CurrentStage, Found->TotalStages);

	if (Found->CurrentStage >= Found->TotalStages)
	{
		Found->bCompleted = true;
		UE_LOG(LogAshenVigil, Log, TEXT("ProgressVigil: '%s' COMPLETED! Reward: %.1f Ash"), *VigilID.ToString(), Found->RewardAsh);
		OnVigilCompleted.Broadcast(*Found);
	}
	else
	{
		OnVigilStageProgressed.Broadcast(*Found);
	}

	return true;
}

void UAshenVigilRegistry::LoadVigilState(const TArray<FVigilRecord>& SavedVigils)
{
	Vigils = SavedVigils;
	UE_LOG(LogAshenVigil, Log, TEXT("LoadVigilState: Restored %d Vigils."), Vigils.Num());
}
