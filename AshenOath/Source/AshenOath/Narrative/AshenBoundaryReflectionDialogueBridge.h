// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenBoundaryReflectionDialogueBridge.generated.h"

/**
 * UAshenBoundaryReflectionDialogueBridge
 * 
 * Formats campfire dialogue reflections after boundary refusal events:
 * - "You didn't follow me into the ruin."
 * - "Because I wasn't going to help you die, Kaelen."
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBoundaryReflectionDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBoundaryReflectionDialogueBridge();

	/** Formats dialogue prompt based on boundary refusal history */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Boundary")
	FText FormatBoundaryDialogue(
		const FString& BasePrompt,
		FName CompanionName,
		bool bHadRecentBoundaryRefusal) const;
};
