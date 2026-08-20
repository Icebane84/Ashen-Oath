// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 549: Ashen Inquisitorial Audit Subsystem

#include "AshenInquisitorialAuditSubsystem.h"

void UAshenInquisitorialAuditSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	SuspicionLevel = 0.0f;
	bPurgeOrderActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenInquisitorialAuditSubsystem: Initialized — Inquisitorial Audit Subsystem ONLINE."));
}

void UAshenInquisitorialAuditSubsystem::EscalateInquisitorialSuspicion(float Delta)
{
	SuspicionLevel = FMath::Clamp(SuspicionLevel + Delta, 0.0f, 100.0f);
	bPurgeOrderActive = (SuspicionLevel >= 80.0f);

	OnSuspicionEscalated.Broadcast(SuspicionLevel, bPurgeOrderActive);

	UE_LOG(LogTemp, Warning, TEXT("UAshenInquisitorialAuditSubsystem: INQUISITORIAL SUSPICION ESCALATED -> Level: %.1f%% | Purge Order: %s"),
		SuspicionLevel, bPurgeOrderActive ? TEXT("ACTIVE — ELDER VALERIUS DISPATCHES PURGERS") : TEXT("INACTIVE"));
}
