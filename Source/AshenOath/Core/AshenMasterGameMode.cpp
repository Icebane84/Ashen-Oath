// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMasterGameMode.h"
#include "Combat/AshenCombatCharacter.h"
#include "AshenVerticalSliceDiagHUD.h"
#include "AshenPAAMasterOrchestrator.h"
#include "Kismet/GameplayStatics.h"

AAshenMasterGameMode::AAshenMasterGameMode()
{
	DefaultPawnClass = AAshenCombatCharacter::StaticClass();
	HUDClass = AAshenVerticalSliceDiagHUD::StaticClass();
}

void AAshenMasterGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AAshenMasterGameMode: Vertical Slice Master GameMode Initialized. Diagnostic HUD set."));
}

void AAshenMasterGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (NewPlayer)
	{
		UE_LOG(LogTemp, Log, TEXT("AAshenMasterGameMode: Player %s logged in."), *NewPlayer->GetName());
	}
}

void AAshenMasterGameMode::StartEncounterTier(uint8 TierIndex)
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenPAAMasterOrchestrator* Orchestrator = GI->GetSubsystem<UAshenPAAMasterOrchestrator>())
		{
			Orchestrator->RunProductionArchitectureAuditPass(FName(TEXT("Encounter.TierTrigger")));
			UE_LOG(LogTemp, Warning, TEXT("AAshenMasterGameMode: Console command triggered Encounter Tier %d"), TierIndex);
		}
	}
}
