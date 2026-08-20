// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPostureMasterBridge.generated.h"

/**
 * UAshenSomaticPostureMasterBridge
 * Orchestration component bridging somatic posture alignment state transitions across domain phenotype adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPostureMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bPostureMasterBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSomaticPostureStatePulse();
};
