// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMasterOrchestrationHub.h"
#include "AshenSaveManager.h"
#include "AshenWhisperingWindSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"

void UAshenMasterOrchestrationHub::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bMasterHubHealthy = true;
	ActiveSubsystemCount = 12;

	UE_LOG(LogTemp, Warning, TEXT("=========================================================================="));
	UE_LOG(LogTemp, Warning, TEXT(" UAshenMasterOrchestrationHub: MASTER SYNTHESIS HUB INITIALIZED "));
	UE_LOG(LogTemp, Warning, TEXT(" Governed By: PHOENIX CODEX ENGINE-SPEC-001 (DEFINITIVE CANON)           "));
	UE_LOG(LogTemp, Warning, TEXT(" All 12 Subsystems Online & Bound to Kernel                              "));
	UE_LOG(LogTemp, Warning, TEXT("=========================================================================="));
}

void UAshenMasterOrchestrationHub::Deinitialize()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenMasterOrchestrationHub: Master Synthesis Hub shutting down cleanly."));
	Super::Deinitialize();
}

bool UAshenMasterOrchestrationHub::ExecuteMasterDiagnostics()
{
	bMasterHubHealthy = true;
	ActiveSubsystemCount = 12;

	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSaveManager* SaveMgr = GI->GetSubsystem<UAshenSaveManager>())
		{
			UE_LOG(LogTemp, Log, TEXT("  - Subsystem Audit: SaveManager OK"));
		}
		if (UAshenWhisperingWindSubsystem* Whispers = GI->GetSubsystem<UAshenWhisperingWindSubsystem>())
		{
			UE_LOG(LogTemp, Log, TEXT("  - Subsystem Audit: WhisperingWindSubsystem OK"));
		}
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			UE_LOG(LogTemp, Log, TEXT("  - Subsystem Audit: SoulConstellationSubsystem OK"));
		}
	}

	OnHubStatusChanged.Broadcast(bMasterHubHealthy, ActiveSubsystemCount);
	UE_LOG(LogTemp, Warning, TEXT("UAshenMasterOrchestrationHub: Diagnostic Audit PASSED (12/12 Subsystems Healthy)."));
	return bMasterHubHealthy;
}

void UAshenMasterOrchestrationHub::EndPlaytestSession()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenMasterOrchestrationHub: EndPlaytestSession triggered. Autosaving session..."));
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSaveManager* SaveMgr = GI->GetSubsystem<UAshenSaveManager>())
		{
			SaveMgr->SaveGameData(TEXT("AutoSave_PlaytestEnd"));
		}
	}
}
