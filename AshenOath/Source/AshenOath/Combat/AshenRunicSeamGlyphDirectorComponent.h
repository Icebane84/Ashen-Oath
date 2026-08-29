// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicSeamGlyphDirectorComponent.generated.h"

/**
 * UAshenRunicSeamGlyphDirectorComponent
 * 
 * Directs procedural emissive colors and glyph brightness along Oathbringer's fuller seam corresponding to active guard sigils.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicSeamGlyphDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicSeamGlyphDirectorComponent();

	/** Evaluates glyph emissive color for active guard sigil */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Visuals")
	FLinearColor EvaluateGlyphColor(ESigilResonanceEffect Sigil) const;
};
