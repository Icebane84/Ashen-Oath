// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenCompanionSilenceTransitionHandler.generated.h"

/**
 * UAshenCompanionSilenceTransitionHandler
 * 
 * Manages smooth transitions between combat engagement and ambient somatic silence modes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSilenceTransitionHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSilenceTransitionHandler();

	/** Determines whether the party should enter Trauma Aftermath silence vs Contemplative silence */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tripartite")
	ETripartiteBehaviorMode ResolvePostCombatSilenceMode(float IntegrationDebt, bool bAnyCompanionDowned) const;
};
