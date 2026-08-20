// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFullPsychologicalLoopOrchestratorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPsychologicalLoopStageCompletedSignature, int32, StageIndex);

/**
 * UAshenFullPsychologicalLoopOrchestratorComponent
 *
 * Core component orchestrating the 7-Stage Closed Psychological Loop:
 * Stage 1: Combat -> Stage 2: Trust -> Stage 3: Soul -> Stage 4: NPC Reaction -> Stage 5: World Reaction -> Stage 6: Memory -> Stage 7: Progression.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFullPsychologicalLoopOrchestratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFullPsychologicalLoopOrchestratorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PsychologicalLoop")
	bool ExecuteFullPsychologicalLoop(AActor* TargetEnemyActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PsychologicalLoop|Events")
	FOnPsychologicalLoopStageCompletedSignature OnStageCompleted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PsychologicalLoop")
	int32 CompletedStageMask = 0;
};
