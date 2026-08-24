// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenQuartzMetaSoundsGraphAdapter.generated.h"

/**
 * UAshenQuartzMetaSoundsGraphAdapter
 * 
 * Feeds stem gain values, pitch bend offsets, and filter parameters directly into the Unreal Engine MetaSounds audio graph.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQuartzMetaSoundsGraphAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQuartzMetaSoundsGraphAdapter();

	/** Formats a MetaSounds input float parameter */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|MetaSounds")
	float FormatMetaSoundsGainParam(float LinearGain) const;
};
