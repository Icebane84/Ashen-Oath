// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireAudioFilterComponent.generated.h"

/**
 * UAshenCampfireAudioFilterComponent
 * 
 * Modulates environmental audio during campfire rest:
 * - Increases acoustic warmth & flame crackle
 * - Applies low-pass filter to distant wind and combat tension tracks
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireAudioFilterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireAudioFilterComponent();

	/** Evaluates rest acoustic warmth scalar */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Hearth")
	float EvaluateAcousticWarmth(ECampfireRestTier RestTier) const;
};
