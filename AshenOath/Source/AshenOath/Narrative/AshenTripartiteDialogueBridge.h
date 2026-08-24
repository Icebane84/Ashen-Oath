// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteDialogueBridge.generated.h"

/**
 * UAshenTripartiteDialogueBridge
 * 
 * Injects tripartite dialogue barks and enforces somatic silence contracts across exploration and aftermath.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteDialogueBridge();

	/** Formats dialogue bark or silence descriptor based on mode */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Tripartite")
	FText FormatTripartiteBark(ETripartiteBehaviorMode Mode, ECompanionAttunementPhase Phase) const;
};
