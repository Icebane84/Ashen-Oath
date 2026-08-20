// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationDependencyGraphComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationNodeEvaluatedSignature, FName, NodeID, float, DependencyWeight);

/**
 * UAshenSoulConstellationDependencyGraphComponent
 *
 * Component treating Soul Constellation as a living dependency graph rather than a static skill tree (Directive #4 & #5).
 * Evaluates node strength directly from psychological memory interpretations.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulConstellationDependencyGraphComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulConstellationDependencyGraphComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConstellationGraph")
	float EvaluateNodeDependencyWeight(FName NodeID, FName InterpretiveLensTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConstellationGraph|Events")
	FOnConstellationNodeEvaluatedSignature OnNodeEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ConstellationGraph")
	int32 TotalActiveGraphNodes = 0;
};
