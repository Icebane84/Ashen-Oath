// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSENarrativeBridge.generated.h"

/**
 * UAshenCSENarrativeBridge
 * 
 * Formats dynamic companion dialogue barks and campfire philosophical debate prompts based on cognitive dissonance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCSENarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCSENarrativeBridge();

	/** Formats dialogue bark for active dissonance tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|CSE")
	FText FormatDissonanceBark(ECognitiveDissonanceTier Tier) const;
};
