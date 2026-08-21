// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicDialogueBridge.generated.h"

/**
 * UAshenRunicDialogueBridge
 * 
 * Formats companion dialogue reactions upon infusing boss cores or memory runes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicDialogueBridge();

	/** Formats dialogue reflecting weapon attunement outcome */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Reliquary")
	FText FormatRunicAttunementDialogue(
		const FString& BasePrompt,
		const FName& RuneId,
		float EffectiveMassKg) const;
};
