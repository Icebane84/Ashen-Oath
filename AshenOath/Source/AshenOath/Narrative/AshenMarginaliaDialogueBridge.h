// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenMarginaliaDialogueBridge.generated.h"

/**
 * UAshenMarginaliaDialogueBridge
 * 
 * Injects written marginalia tension and corrections into next-day dialogue prompts:
 * - "I saw what you wrote in the margins."
 * - Unlocks conversational confrontation barks based on recent cross-outs
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMarginaliaDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMarginaliaDialogueBridge();

	/** Formats dialogue response acknowledging recent margin notes */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Marginalia")
	FText FormatMarginaliaDialoguePrompt(
		const FString& BasePrompt,
		EMarginaliaAuthor Author,
		const FString& InscriptionText) const;
};
