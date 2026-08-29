// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryPalaceWeavingLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryWeavingLocusActivatedSignature, FName, MemoryNodeTag, bool, bGraceSelected);

/**
 * AAshenMemoryPalaceWeavingLocusActor
 * Interactive physical locus in level space where players execute Grace vs Accountability lens selection (UMB-INT-001 Memory Slice),
 * unsealing nodes in the Memory Palace graph and restoring +20.0 Sanity.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceWeavingLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryPalaceWeavingLocusActor();

	/** Executes a memory weaving pass, resolving the locus and unsealing the node */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeavingLocus")
	void ExecuteMemoryWeavingPass(bool bSelectGraceLens, AActor* Interactor = nullptr);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeavingLocus|Events")
	FOnMemoryWeavingLocusActivatedSignature OnWeavingLocusActivated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|WeavingLocus")
	FName BoundMemoryNodeTag = FName(TEXT("can-grace_vs_accountability"));

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeavingLocus")
	bool bIsWeaved = false;
};
