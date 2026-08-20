// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryPalaceWeavingLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryWeavingLocusActivatedSignature, FName, MemoryNodeTag, bool, bGraceSelected);

/**
 * AAshenMemoryPalaceWeavingLocusActor
 *
 * Interactive physical locus in level space where players execute Grace vs Accountability lens selection (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceWeavingLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryPalaceWeavingLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeavingLocus")
	void ExecuteMemoryWeavingPass(bool bSelectGraceLens);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeavingLocus|Events")
	FOnMemoryWeavingLocusActivatedSignature OnWeavingLocusActivated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|WeavingLocus")
	FName BoundMemoryNodeTag = FName(TEXT("can-grace_vs_accountability"));

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeavingLocus")
	bool bIsWeaved = false;
};
