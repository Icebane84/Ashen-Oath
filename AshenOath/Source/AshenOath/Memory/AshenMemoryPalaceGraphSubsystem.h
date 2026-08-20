// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceGraphSubsystem.generated.h"

/**
 * UAshenMemoryPalaceGraphSubsystem
 * GameInstance Subsystem managing the Memory Palace graph topology, node connections, unsealing state, and traversal paths.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryPalaceGraphSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory")
	TMap<FName, FMemoryGraphNode> NodeGraph;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool RegisterNode(const FMemoryGraphNode& InNode);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool UnsealNode(FName NodeID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool ConnectNodes(FName SourceNodeID, FName TargetNodeID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool GetNode(FName NodeID, FMemoryGraphNode& OutNode) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	int32 GetUnsealedNodeCount() const;
};
