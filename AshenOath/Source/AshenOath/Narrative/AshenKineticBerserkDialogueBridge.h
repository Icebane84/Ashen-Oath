// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenKineticBerserkDialogueBridge.generated.h"

/**
 * UAshenKineticBerserkDialogueBridge
 * 
 * Injects narrative barks when perfect angular ripostes and heavy kinetic fractures occur.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKineticBerserkDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenKineticBerserkDialogueBridge();

	/** Formats dialogue based on angular counter zone */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|KineticBerserk")
	FText FormatRiposteBark(EAshenCounterAttackZone CounterZone) const;
};
