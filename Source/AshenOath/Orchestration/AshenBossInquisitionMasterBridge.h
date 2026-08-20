// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossInquisitionMasterBridge.generated.h"

/**
 * UAshenBossInquisitionMasterBridge
 * Master bridge broadcasting boss state events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossInquisitionMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossInquisitionMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bBossBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBossEventPulse(FName BossID, uint8 PhaseIndex);
};
