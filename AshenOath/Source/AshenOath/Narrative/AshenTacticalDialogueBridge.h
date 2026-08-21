// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTacticalDialogueBridge.generated.h"

/**
 * UAshenTacticalDialogueBridge
 * 
 * Injects instant companion tactical response callouts into dialogue queues.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalDialogueBridge();

	/** Formats companion tactical bark based on command type */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Tactics")
	FText FormatTacticalBark(
		const FName& CompanionId,
		ETacticalCommandType CommandType) const;
};
