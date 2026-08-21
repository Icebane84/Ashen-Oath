// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireTraumaDialogueBridge.generated.h"

/**
 * UAshenCampfireTraumaDialogueBridge
 * 
 * Injects campfire rest reflections and companion seating context into dialogue.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireTraumaDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireTraumaDialogueBridge();

	/** Formats dialogue reflecting companion seating context */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Hearth")
	FText FormatSeatingDialogue(
		const FString& BasePrompt,
		FName CompanionName,
		ECompanionHearthSeating Seating) const;
};
