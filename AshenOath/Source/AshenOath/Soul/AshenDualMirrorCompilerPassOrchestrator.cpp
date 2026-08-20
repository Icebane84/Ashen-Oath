// Copyright Phoenix Protocol / Ashen Oath. All rights reserved.

#include "AshenDualMirrorCompilerPassOrchestrator.h"

void UAshenDualMirrorCompilerPassOrchestrator::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("UAshenDualMirrorCompilerPassOrchestrator initialized."));
}

void UAshenDualMirrorCompilerPassOrchestrator::OrchestrateDualPasses(FName MemoryID, float IntegrationStrength, float VoidErosionStrength)
{
    TotalDualPassesOrchestrated++;
    UE_LOG(LogTemp, Log, TEXT("Orchestrating dual mirror passes for %s (Integration=%f, VoidErosion=%f)."), *MemoryID.ToString(), IntegrationStrength, VoidErosionStrength);
    OnPassOrchestrated.Broadcast(MemoryID, IntegrationStrength, VoidErosionStrength);
}
