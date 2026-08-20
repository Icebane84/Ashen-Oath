// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceMasterBridge.generated.h"

/**
 * UAshenMemoryPalaceMasterBridge
 * Master domain bridge broadcasting Memory Palace node unsealing, bridge reconstruction, and trauma shifts across all domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bMemoryBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastLocusUnsealed(FName NodeID, EMemoryNodeType NodeType);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBridgeReconstructed(FName BridgeID);
};
