// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEliteInquisitionMasterBridge.generated.h"

/**
 * UAshenEliteInquisitionMasterBridge
 * Master bridge broadcasting elite inquisition encounters across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEliteInquisitionMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEliteInquisitionMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bEliteBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastEliteEventPulse(FName EliteID, uint8 StateEnum);
};
