// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGrandMasterMasterBridge.generated.h"

/**
 * UAshenGrandMasterMasterBridge
 * Orchestration component bridging Grand Master Milestone 1100 synthesis transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGrandMasterMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGrandMasterMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bGrandMasterBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastGrandMasterStatePulse();
};
