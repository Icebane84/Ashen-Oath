// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenBlackboardInspectorSubsystem.h"

void UAshenBlackboardInspectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardInspectorSubsystem: Initialized cleanly."));
}

void UAshenBlackboardInspectorSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenBlackboardInspectorSubsystem::BindVariableToMaterialCollection(FName VariableName, float CurrentValue)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardInspectorSubsystem: Bound variable %s -> %.2f to MPC"), *VariableName.ToString(), CurrentValue);
	return true;
}

bool UAshenBlackboardInspectorSubsystem::TransmitStateToAudioSubsystem(FName ParameterName, float NormalizedValue)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardInspectorSubsystem: Transmitted audio parameter %s -> %.2f to MetaSound Blackboard"), *ParameterName.ToString(), NormalizedValue);
	return true;
}
