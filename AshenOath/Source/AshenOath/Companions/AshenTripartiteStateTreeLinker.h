// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteStateTreeLinker.generated.h"

/**
 * UAshenTripartiteStateTreeLinker
 * 
 * Bridges StateTree evaluator conditions with runtime EQS position queries and silence rules.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteStateTreeLinker : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteStateTreeLinker();

	/** Evaluates whether StateTree should permit casual companion barks */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite|StateTree")
	bool ShouldPermitDialogueBarks(ETripartiteBehaviorMode Mode) const;
};
