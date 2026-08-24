// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteMasterBridge.generated.h"

/**
 * UAshenTripartiteMasterBridge
 * 
 * Master orchestrator unifying the tripartite cognitive loop across StateTree AI, EQS director, and Haptics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTripartiteMasterBridge();

	/** Broadcasts a tripartite state synchronization event */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Tripartite")
	void BroadcastTripartiteSync(ETripartiteBehaviorMode Mode, float AttunementScore);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Tripartite")
	FOnAttunementScoreUpdated OnAttunementBroadcaster;
};
