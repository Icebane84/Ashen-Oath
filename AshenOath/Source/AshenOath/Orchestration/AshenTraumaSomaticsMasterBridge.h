// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaSomaticsMasterBridge.generated.h"

/**
 * UAshenTraumaSomaticsMasterBridge
 * 
 * Master orchestrator unifying the procedural trauma material pipeline, blade soot deposition, bio-haptics, and HUD.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaSomaticsMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaSomaticsMasterBridge();

	/** Broadcasts a somatic stage evolution across all game domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Somatics")
	void BroadcastSomaticEvolution(ETraumaSomaticStage Stage, float VeinCorruption);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Somatics")
	FOnSomaticStageChanged OnSomaticEvolutionBroadcaster;
};
