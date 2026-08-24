// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzDialogueBridge.generated.h"

/**
 * UAshenQuartzDialogueBridge
 * 
 * Synchronizes companion contextual vocal barks with the Quartz musical downbeat during flow state and crisis transitions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzDialogueBridge();

	/** Formats dialogue bark for flow state or crisis transition */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Audio")
	FText FormatFlowStateBark(ECombatFlowState FlowState) const;
};
