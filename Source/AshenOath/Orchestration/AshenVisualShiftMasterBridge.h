// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVisualShiftMasterBridge.generated.h"

/**
 * UAshenVisualShiftMasterBridge
 * Master bridge broadcasting visual shift events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVisualShiftMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenVisualShiftMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bVisualShiftBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastVisualShiftPulse(float CorruptionIntensity, float DualityBlend);
};
