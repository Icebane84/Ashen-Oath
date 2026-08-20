// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMaterialStateTelemetrySubsystem.h"

void UAshenMaterialStateTelemetrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenMaterialStateTelemetrySubsystem: Material State Telemetry Subsystem initialized."));
}

void UAshenMaterialStateTelemetrySubsystem::BroadcastMaterialParameter(FName ParamName, float ScalarVal, FLinearColor VectorVal)
{
	if (OnMaterialTelemetryUpdated.IsBound())
	{
		OnMaterialTelemetryUpdated.Broadcast(ParamName, ScalarVal, VectorVal);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenMaterialStateTelemetrySubsystem: Parameter '%s' broadcasted (Scalar: %.2f)."), *ParamName.ToString(), ScalarVal);
}
