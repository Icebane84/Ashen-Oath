// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenPromiseReflectionDialogueBridge.generated.h"

/**
 * UAshenPromiseReflectionDialogueBridge
 * 
 * Injects active, fulfilled, or broken vows into campfire dialogue trees.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPromiseReflectionDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPromiseReflectionDialogueBridge();

	/** Formats dialogue reflecting a sworn vow */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Promise")
	FText FormatPromiseDialogue(
		const FString& BasePrompt,
		const FCanonicalPromiseRecord& PromiseRecord) const;
};
