// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCompanionDialogueBranchingSubsystem.h"

void UAshenCompanionDialogueBranchingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDialogueBranchingSubsystem: Dialogue Branching Subsystem initialized."));
}

void UAshenCompanionDialogueBranchingSubsystem::Deinitialize() { Super::Deinitialize(); }

FText UAshenCompanionDialogueBranchingSubsystem::SelectDynamicDialogueLine(FName CompanionID, uint8 EmpathicProfileEnum, float TrustLevel)
{
	FText Line = FText::FromString(FString::Printf(TEXT("%s: The sifting shadows grow heavy..."), *CompanionID.ToString()));
	if (TrustLevel > 0.70f)
	{
		Line = FText::FromString(FString::Printf(TEXT("%s: I stand with you, Kaelen. Together."), *CompanionID.ToString()));
	}
	if (OnDialogueSelected.IsBound())
	{
		OnDialogueSelected.Broadcast(CompanionID, Line);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDialogueBranchingSubsystem: Line selected for %s: '%s'"), *CompanionID.ToString(), *Line.ToString());
	return Line;
}
