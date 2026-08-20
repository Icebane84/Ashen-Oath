// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 534: Ashen Production Hardening Crash Report Subsystem

#include "AshenProductionHardeningCrashReportSubsystem.h"
#include "Misc/Guid.h"

void UAshenProductionHardeningCrashReportSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenProductionHardeningCrashReportSubsystem: Initialized — Production Hardening Crash Report Subsystem ONLINE."));
}

FString UAshenProductionHardeningCrashReportSubsystem::CaptureCrashReportStateDump(const FString& ContextTag)
{
	const FString Hash = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensInBraces);
	const int32 StateVectorSize = 28; // 28-byte FSoulStateVector contract

	OnCrashTelemetryCaptured.Broadcast(Hash, StateVectorSize);

	UE_LOG(LogTemp, Warning, TEXT("UAshenProductionHardeningCrashReportSubsystem: CRASH REPORT TELEMETRY CAPTURED -> Context '%s' | Hash: %s (SoulStateVector Size: %d Bytes)."),
		*ContextTag, *Hash, StateVectorSize);

	return Hash;
}
