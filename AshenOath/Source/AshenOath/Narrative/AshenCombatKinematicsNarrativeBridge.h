// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsNarrativeBridge.generated.h"

/**
 * UAshenCombatKinematicsNarrativeBridge
 * 
 * Triggers dynamic companion dialogue barks during guard break stagger and perfect deflection ripostes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatKinematicsNarrativeBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsNarrativeBridge();

	/** Formats dialogue bark for the active combat kinematics event */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Kinematics")
	FText FormatKinematicsBark(EPoiseStaggerState StaggerState, bool bPerfectRiposte) const;
};
