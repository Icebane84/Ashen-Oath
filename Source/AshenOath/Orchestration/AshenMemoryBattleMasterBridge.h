// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryBattleMasterBridge.generated.h"

/**
 * UAshenMemoryBattleMasterBridge
 * Master bridge broadcasting memory battle events across all domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattleMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBattleMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bMemoryBattleBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastMemoryBattlePulse(FName EchoID, bool bVictory, float HarmonyReward);
};
