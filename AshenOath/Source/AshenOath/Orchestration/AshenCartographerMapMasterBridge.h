// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCartographerMapMasterBridge.generated.h"

/**
 * UAshenCartographerMapMasterBridge
 * Orchestration component bridging Cartographer Map state vector transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCartographerMapMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCartographerMapMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bMapMasterBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastMapStateVectorPulse();
};
