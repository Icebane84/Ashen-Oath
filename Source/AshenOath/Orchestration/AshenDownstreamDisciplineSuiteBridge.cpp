// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 813: Ashen Downstream Discipline Suite Bridge

#include "AshenDownstreamDisciplineSuiteBridge.h"

void UAshenDownstreamDisciplineSuiteBridge::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalDisciplinesActive = 6;
	UE_LOG(LogTemp, Log, TEXT("UAshenDownstreamDisciplineSuiteBridge: Initialized — Downstream Discipline Suite Bridge ONLINE."));
}

void UAshenDownstreamDisciplineSuiteBridge::SynchronizeDisciplineSuites()
{
	OnSuiteSynchronized.Broadcast(FName(TEXT("Suite.MasterProductionSuite")), TotalDisciplinesActive);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDownstreamDisciplineSuiteBridge: DISCIPLINE SUITES SYNCHRONIZED -> 6 Production Suites Active (GAS, Animation, Audio, VFX/Shader, AI/Companions, UX/Haptics)."));
}
