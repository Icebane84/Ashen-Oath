// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVeilPhaseFilterMasterBridge.generated.h"

/**
 * UAshenVeilPhaseFilterMasterBridge
 * Orchestration component bridging veil phase filter transitions with downstream domain phenotype adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVeilPhaseFilterMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseFilterMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bVeilFilterBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastVeilPhaseFilterStatePulse();
};
