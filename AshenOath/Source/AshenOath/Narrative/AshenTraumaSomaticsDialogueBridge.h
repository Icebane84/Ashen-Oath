// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaSomaticsDialogueBridge.generated.h"

/**
 * UAshenTraumaSomaticsDialogueBridge
 * 
 * Injects Garrett and Serafina's somatic observation barks when Kaelen's vein corruption crosses critical thresholds.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaSomaticsDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaSomaticsDialogueBridge();

	/** Formats companion observation bark from somatic stage */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Somatics")
	FText FormatSomaticObservationBark(ETraumaSomaticStage Stage) const;
};
