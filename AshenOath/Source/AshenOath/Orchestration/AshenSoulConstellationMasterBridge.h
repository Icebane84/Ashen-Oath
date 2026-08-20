// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenSoulConstellationMasterBridge.generated.h"

/**
 * UAshenSoulConstellationMasterBridge
 * Master bridge orchestrating state synchronisation between USoulConstellationSubsystem and all peer subsystems.
 * Listens to OnStateVectorInvalidated and broadcasts domain-targeted synchronisation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulConstellationMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSoulConstellationMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bKernelBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastKernelSynchronisationPulse();
};
