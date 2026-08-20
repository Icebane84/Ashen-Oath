// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMemoryNodeAnchorRegistrySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryAnchorRegisteredSignature, FName, NodeID, FName, LabelCategory);

/**
 * UAshenMemoryNodeAnchorRegistrySubsystem
 *
 * Subsystem registering 10-Node Label memory anchors (PRS-001 Ashen Genesis Knowledge Graph Federation Layer).
 */
UCLASS()
class ASHENOATH_API UAshenMemoryNodeAnchorRegistrySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryRegistry")
	bool RegisterMemoryAnchorNode(FName NodeID, FName LabelCategory);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryRegistry|Events")
	FOnMemoryAnchorRegisteredSignature OnMemoryAnchorRegistered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryRegistry")
	int32 TotalRegisteredAnchors = 0;
};
