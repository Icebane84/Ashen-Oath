// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenHarmonizedReflectionDialogueBridge.generated.h"

/**
 * UAshenHarmonizedReflectionDialogueBridge
 * 
 * Injects campfire dialogue reflections celebrating synchronized tripartite combat triumphs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHarmonizedReflectionDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHarmonizedReflectionDialogueBridge();

	/** Formats dialogue reflecting unbroken group resonance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Trio")
	FText FormatResonanceDialogue(
		const FString& BasePrompt,
		int32 TotalHarmonizedFinishers) const;
};
