// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicForgeNarrativeBridge.generated.h"

/**
 * UAshenRunicForgeNarrativeBridge
 * 
 * Formats companion dialogue barks during anvil forging sessions and blade ascension milestones.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicForgeNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicForgeNarrativeBridge();

	/** Formats dialogue bark for forge events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|RunicForge")
	FText FormatForgeBark(EOathbringerAscensionTier Tier, ESigilResonanceEffect Sigil) const;
};
