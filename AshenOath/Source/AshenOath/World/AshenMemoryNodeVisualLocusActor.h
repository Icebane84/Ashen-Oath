// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryNodeVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryNodeLocusUpdatedSignature, FName, BoundNodeID, bool, bIsStabilized);

/**
 * AAshenMemoryNodeVisualLocusActor
 *
 * World Actor rendering memory node orb loci on level geometry (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API AAshenMemoryNodeVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryNodeVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryLocus")
	void SetMemoryNodeState(FName NodeID, bool bStabilized);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryLocus|Events")
	FOnMemoryNodeLocusUpdatedSignature OnMemoryNodeLocusUpdated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryLocus")
	FName ActiveBoundNodeID = FName(TEXT("can-seeds_of_corruption"));

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryLocus")
	bool bIsNodeStabilized = false;
};
