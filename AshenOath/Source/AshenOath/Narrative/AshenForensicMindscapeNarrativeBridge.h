// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenForensicMindscapeNarrativeBridge.generated.h"

/**
 * UAshenForensicMindscapeNarrativeBridge
 * 
 * Formats companion dialogue barks for clue discoveries, contradiction confrontations, and Memory Palace epiphanies.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenForensicMindscapeNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenForensicMindscapeNarrativeBridge();

	/** Formats dialogue bark for investigation milestones */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Forensic")
	FText FormatInvestigationBark(EMemoryReconstructionState State, EForensicClueCategory Category) const;
};
