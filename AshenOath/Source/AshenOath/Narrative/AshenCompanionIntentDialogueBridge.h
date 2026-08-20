// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenCompanionIntentDialogueBridge.generated.h"

/**
 * UAshenCompanionIntentDialogueBridge
 * 
 * Injects historical formation break intent context into dialogue choice prompts:
 * - "Why did you charge the gate alone?"
 * - "I knew you would follow me."
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionIntentDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionIntentDialogueBridge();

	/** Formats dialogue response reflecting recent tactical intent */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Intent")
	FText FormatIntentDialoguePrompt(
		const FString& BasePrompt,
		FName CompanionName,
		ECompanionTacticalResponse Response) const;
};
