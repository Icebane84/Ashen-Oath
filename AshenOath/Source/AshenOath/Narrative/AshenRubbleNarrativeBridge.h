// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubbleNarrativeBridge.generated.h"

/**
 * UAshenRubbleNarrativeBridge
 * 
 * Generates contextual companion callouts for structural collapse telegraphs and tactical demolition advice.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubbleNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubbleNarrativeBridge();

	/** Formats dialogue bark for masonry collapse or demolition */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Rubble")
	FText FormatCollapseBark(EMasonryCollapseState CollapseState, EDemolitionToolType DemolitionTool) const;
};
