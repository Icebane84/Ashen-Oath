// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerStanceNarrativeBridge.generated.h"

/**
 * UAshenOathbringerStanceNarrativeBridge
 * 
 * Formats companion dialogue barks when Kaelen executes clean Flow Glint stance cancels and delivers guard-shattering Mordhau blows.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerStanceNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerStanceNarrativeBridge();

	/** Formats dialogue bark for stance events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Stance")
	FText FormatStanceBark(EOathbringerMartialStance Stance, bool bCleanFlowGlint) const;
};
