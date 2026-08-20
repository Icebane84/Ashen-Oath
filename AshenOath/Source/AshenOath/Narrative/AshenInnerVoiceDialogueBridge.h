// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenInnerVoiceDialogueBridge.generated.h"

/**
 * UAshenInnerVoiceDialogueBridge
 * 
 * Bridges recent inner voice monologue into dialogue interaction prompts:
 * - Injects internal conflict thoughts into dialogue wheels
 * - Modulates dialogue choice availability based on active voice channel
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerVoiceDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceDialogueBridge();

	/** Injects recent monologue thought into dialogue choice prompt */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Voice")
	FText FormatDialogueThoughtPrompt(const FString& RawPrompt, const FString& MonologueThought) const;
};
