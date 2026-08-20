// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSovereignPhoenixMasterBridge.generated.h"

/**
 * UAshenSovereignPhoenixMasterBridge
 * Master Orchestration component bridging Sovereign Phoenix state transitions across all 12 domain vertical slice state adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSovereignPhoenixMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSovereignPhoenixMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bSovereignMasterBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSovereignPhoenixStatePulse();
};
