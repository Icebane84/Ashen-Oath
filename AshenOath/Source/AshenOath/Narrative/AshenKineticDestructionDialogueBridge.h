// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenKineticDestructionDialogueBridge.generated.h"

/**
 * UAshenKineticDestructionDialogueBridge
 * 
 * Injects commentary regarding Kaelen's terrifying dark kinetic destruction
 * into campfire reflections.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticDestructionDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticDestructionDialogueBridge();

	/** Formats companion reaction to devastating kinetic cleaves */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Kinetic")
	FText FormatDestructionDialogue(
		const FString& BasePrompt,
		FName CompanionName,
		int32 ShatteredStructuresCount) const;
};
