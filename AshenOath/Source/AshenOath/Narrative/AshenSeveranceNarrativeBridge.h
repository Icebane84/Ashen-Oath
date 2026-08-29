// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceNarrativeBridge.generated.h"

/**
 * UAshenSeveranceNarrativeBridge
 * 
 * Contextual narrative dialogue barks from Garrett and Serafina reacting to gruesome executions and decapitations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSeveranceNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSeveranceNarrativeBridge();

	/** Formats dialogue bark for severance event */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Severance")
	FText FormatExecutionBark(ESeveranceSeverityTier Severity) const;
};
