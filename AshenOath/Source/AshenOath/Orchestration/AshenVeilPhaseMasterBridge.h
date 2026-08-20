// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVeilPhaseMasterBridge.generated.h"

/**
 * UAshenVeilPhaseMasterBridge
 * Orchestration component bridging veil phase state transitions with downstream domain phenotype adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVeilPhaseMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bVeilBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastVeilPhaseStatePulse();
};
