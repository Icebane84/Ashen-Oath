// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenInnerWorldMasterBridge.generated.h"

/**
 * UAshenInnerWorldMasterBridge
 * Orchestration component bridging Inner World memory state transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerWorldMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerWorldMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bInnerWorldBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastInnerWorldStatePulse();
};
