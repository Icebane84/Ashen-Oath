// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 413: Ashen Dynamic Dialogue Consequence Subsystem

#include "AshenDynamicDialogueConsequenceSubsystem.h"

void UAshenDynamicDialogueConsequenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GlobalAlignment = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicDialogueConsequenceSubsystem: Initialized — Dynamic Moral Consequence Engine ONLINE."));
}

void UAshenDynamicDialogueConsequenceSubsystem::RecordMoralChoiceConsequence(FName ChoiceID, float AlignmentShift)
{
	GlobalAlignment = FMath::Clamp(GlobalAlignment + AlignmentShift, -100.0f, 100.0f);
	OnMoralConsequenceRecorded.Broadcast(ChoiceID, AlignmentShift);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicDialogueConsequenceSubsystem: MORAL CHOICE RECORDED — '%s' (%+f) -> Global Alignment: %.1f."),
		*ChoiceID.ToString(), AlignmentShift, GlobalAlignment);
}
