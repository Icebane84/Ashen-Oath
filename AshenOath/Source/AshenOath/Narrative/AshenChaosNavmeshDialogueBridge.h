// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosNavmeshDialogueBridge.generated.h"

/**
 * UAshenChaosNavmeshDialogueBridge
 * 
 * Injects companion warning barks when structural collapses block navigation paths.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosNavmeshDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosNavmeshDialogueBridge();

	/** Formats dialogue bark based on fracture severity and obstruction state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Chaos")
	FText FormatChaosDestructionBark(EChaosFractureSeverity Severity, ENavmeshObstructionState Obstruction) const;
};
