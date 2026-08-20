// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPRSNodeVisualizerAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPRSNodeVisualizedSignature, FName, NodeID, int32, ConnectedEdgeCount);

/**
 * AAshenPRSNodeVisualizerAnchorActor
 *
 * Interactive World Actor rendering PRS node connections diegetically in editor/game worlds.
 */
UCLASS()
class ASHENOATH_API AAshenPRSNodeVisualizerAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPRSNodeVisualizerAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PRSVisualizer")
	void RenderNodeConnections(FName NodeID, int32 ConnectedEdgeCount = 3);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PRSVisualizer|Events")
	FOnPRSNodeVisualizedSignature OnNodeVisualized;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PRSVisualizer")
	bool bIsVisualizing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|PRSVisualizer")
	FName TargetedPRSNodeID;
};
