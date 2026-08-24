// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10MasterBridge.generated.h"

/**
 * UAshenScenario10MasterBridge
 * 
 * Master orchestrator connecting tripartite apotheosis, consequence endings, Solfeggio audio triad, and campaign save states.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario10MasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario10MasterBridge();

	/** Broadcasts apotheosis resonance updates */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Scenario10")
	void BroadcastApotheosisUpdate(EApotheosisResonanceStage Stage, float Resonance01);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Scenario10")
	FOnApotheosisStageChanged OnApotheosisBroadcaster;
};
