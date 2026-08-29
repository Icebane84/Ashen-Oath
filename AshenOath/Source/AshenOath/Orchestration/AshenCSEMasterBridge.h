// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSEMasterBridge.generated.h"

/**
 * UAshenCSEMasterBridge
 * 
 * Master orchestrator bridging the CSE world subsystem, Dissonance Quest Board, Forensic Journal, and companion behavior trees.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCSEMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCSEMasterBridge();

	/** Broadcasts live CSE synchronization update across listener domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|CSE")
	void BroadcastCSEState(float DissonanceIndex, ECognitiveDissonanceTier Tier);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|CSE")
	FOnCognitiveDissonanceShifted OnCSEBroadcaster;
};
