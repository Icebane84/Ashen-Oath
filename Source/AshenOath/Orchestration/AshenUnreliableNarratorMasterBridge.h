// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnreliableNarratorMasterBridge.generated.h"

/**
 * UAshenUnreliableNarratorMasterBridge
 * Master bridge broadcasting hallucination events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNarratorMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnreliableNarratorMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bNarratorBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastHallucinationPulse(uint8 StateEnum);
};
