// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCampfireRestMasterBridge.generated.h"

/**
 * UAshenCampfireRestMasterBridge
 * Master bridge broadcasting campfire and heartstone events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireRestMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCampfireRestMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCampfireBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastCampfireRestPulse(FName CampfireID, uint8 StateEnum);
};
