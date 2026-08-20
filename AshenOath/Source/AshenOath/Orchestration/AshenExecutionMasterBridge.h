// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenExecutionMasterBridge.generated.h"

/**
 * UAshenExecutionMasterBridge
 * Master bridge broadcasting execution events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenExecutionMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenExecutionMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bExecutionBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastExecutionFlourishPulse(uint8 StanceEnum);
};
