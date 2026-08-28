// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenBladeSanityNarrativeBridge.generated.h"

/**
 * UAshenBladeSanityNarrativeBridge
 * 
 * Generates contextual companion dialogue barks during mental collapse, Eldrin whisper possession, and flow state catharsis.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSanityNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSanityNarrativeBridge();

	/** Formats dialogue bark for active mental state and flow */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Convergence")
	FText FormatConvergenceBark(ESanityDissonanceTier Tier, bool bFlowActive) const;
};
