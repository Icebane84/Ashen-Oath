// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 351: Ashen Prismatic Realm Veil Subsystem

#include "AshenPrismaticRealmVeilSubsystem.h"

void UAshenPrismaticRealmVeilSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentVeilState = EAshenWorldVeilState::MaterialWorld;
	UE_LOG(LogTemp, Log, TEXT("UAshenPrismaticRealmVeilSubsystem: Initialized — Prismatic Realm & Veil Subsystem ONLINE."));
}

void UAshenPrismaticRealmVeilSubsystem::ShiftWorldVeilState(EAshenWorldVeilState NewState)
{
	CurrentVeilState = NewState;
	const float Dissonance = (NewState == EAshenWorldVeilState::PrismaticVoidPhase) ? 2.5f : 1.0f;

	OnVeilStateChanged.Broadcast(NewState, Dissonance);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPrismaticRealmVeilSubsystem: REALM SHIFT -> State %d (Dissonance Factor: %.1fx)."),
		(int32)NewState, Dissonance);
}
