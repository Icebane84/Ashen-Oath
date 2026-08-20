// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AshenMasterGameMode.generated.h"

class UAshenPAAMasterOrchestrator;

/**
 * AAshenMasterGameMode
 *
 * Master C++ GameMode for the vertical slice level.
 * Configures default HUD class to AAshenVerticalSliceDiagHUD, initializes
 * UAshenPAAMasterOrchestrator on match start, and manages party companion spawning.
 */
UCLASS()
class ASHENOATH_API AAshenMasterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAshenMasterGameMode();

protected:
	virtual void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	/** Triggers an encounter tier breach through the Master PAA Orchestrator. */
	UFUNCTION(Exec, Category = "AshenOath|GameMode")
	void StartEncounterTier(uint8 TierIndex);
};
