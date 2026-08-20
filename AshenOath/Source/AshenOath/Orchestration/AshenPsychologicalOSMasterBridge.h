// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPsychologicalOSMasterBridge.generated.h"

/**
 * UAshenPsychologicalOSMasterBridge
 * Orchestration component bridging Psychological OS state transitions across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychologicalOSMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPsychologicalOSMasterBridge();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bPOSBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastPOSStatePulse();
};
