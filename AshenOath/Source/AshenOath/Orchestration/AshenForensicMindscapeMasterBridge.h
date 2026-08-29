// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeMasterBridge.generated.h"

/**
 * UAshenForensicMindscapeMasterBridge
 * 
 * Master orchestrator connecting overland crime scenes, Forensic Journal UI, Memory Palace 3D dioramas, and GAS abilities.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenForensicMindscapeMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeMasterBridge();

	/** Broadcasts live deduction synthesis update across game modules */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Forensic")
	void BroadcastDeductionUpdate(FName CaseId, float SynthesisScore);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Forensic")
	FOnMemoryDeductionBoardUpdated OnDeductionBroadcaster;
};
