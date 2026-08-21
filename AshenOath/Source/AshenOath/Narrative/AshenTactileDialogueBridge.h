// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenTactileDialogueBridge.generated.h"

/**
 * UAshenTactileDialogueBridge
 * 
 * Injects tactile feedback cues into narrative dialogue sequences.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTactileDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTactileDialogueBridge();

	/** Formats dialogue reflecting active haptic feedback profile */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Haptics")
	FText FormatTactileDialogue(
		const FString& BasePrompt,
		ETactileWhisperChannel Channel,
		bool bLockoutEngaged) const;
};
