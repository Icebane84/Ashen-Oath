// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenAlchemicalSlagNarrativeBridge.generated.h"

/**
 * UAshenAlchemicalSlagNarrativeBridge
 * 
 * Formats companion dialogue barks from Garrett when Kaelen coats Oathbringer or detonates large thermal reactions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalSlagNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalSlagNarrativeBridge();

	/** Formats dialogue bark for coating and reaction events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|AlchemicalSlag")
	FText FormatReactionBark(EThermalReactionType Reaction, EAlchemicalBladeCoating Coating) const;
};
