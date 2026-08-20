// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenProductionHardeningCrashReportSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrashTelemetryCapturedSignature, FString, TelemetryHash, int32, StateVectorByteSize);

/**
 * UAshenProductionHardeningCrashReportSubsystem
 *
 * World Subsystem capturing callstack telemetry, state vector dumps, and memory heap statistics.
 */
UCLASS()
class ASHENOATH_API UAshenProductionHardeningCrashReportSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ProductionHardening")
	FString CaptureCrashReportStateDump(const FString& ContextTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ProductionHardening|Events")
	FOnCrashTelemetryCapturedSignature OnCrashTelemetryCaptured;
};
