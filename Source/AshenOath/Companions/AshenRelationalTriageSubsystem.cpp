// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenRelationalTriageSubsystem.h"

void UAshenRelationalTriageSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveStance = ECompiledRelationalStance::WeaverStance;
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTriageSubsystem: Initialized Relational Triage Subsystem (Default Stance: Weaver)."));
}
void UAshenRelationalTriageSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenRelationalTriageSubsystem::RecordTriageResolution(FName IncidentID, EInterpretiveTherapyLens Lens, ECompiledRelationalStance ResultingStance)
{
	FTriageIncidentRecord Record;
	Record.IncidentID = IncidentID;
	Record.SelectedLens = Lens;
	Record.ResultingStance = ResultingStance;
	Record.BurnoutDecayModifier = (Lens == EInterpretiveTherapyLens::Grace) ? 1.25f : 1.0f;

	ResolvedIncidents.Add(Record);
	ActiveStance = ResultingStance;

	UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTriageSubsystem: TRIAGE RESOLVED -> '%s' (Lens: %d, Stance: %d, Total: %d)"),
		*IncidentID.ToString(), static_cast<int32>(Lens), static_cast<int32>(ResultingStance), ResolvedIncidents.Num());
}
