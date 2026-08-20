// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryPalaceNodeAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryNodeAnchoredSignature, FName, MemoryID, float, ResonancePower);

/**
 * AAshenMemoryPalaceNodeAnchorActor
 *
 * Interactive World Actor anchoring Memory Palace nodes in physical level space.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceNodeAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMemoryPalaceNodeAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryPalace")
	void AnchorMemoryNode(FName MemoryID, float ResonancePower = 100.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryPalace|Events")
	FOnMemoryNodeAnchoredSignature OnMemoryNodeAnchored;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryPalace")
	bool bIsAnchored = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|MemoryPalace")
	FName AnchoredMemoryID;
};
