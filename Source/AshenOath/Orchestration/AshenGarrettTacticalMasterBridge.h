// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTacticalMasterBridge.generated.h"

/**
 * UAshenGarrettTacticalMasterBridge
 * Master bridge broadcasting gadget events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTacticalMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bTacticalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastGadgetEventPulse(FName GadgetName);
};
