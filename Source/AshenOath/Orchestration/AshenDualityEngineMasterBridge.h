// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualityEngineMasterBridge.generated.h"

/**
 * UAshenDualityEngineMasterBridge
 * Orchestration component bridging Duality Engine transformation state pulses across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityEngineMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualityEngineMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bDualityBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastDualityStatePulse();
};
