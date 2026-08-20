// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionFatigueMasterBridge.generated.h"

/**
 * UAshenCompanionFatigueMasterBridge
 * Master bridge broadcasting companion fatigue shifts, vulnerability entries, and Resonance Sync events across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFatigueMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionFatigueMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCompanionBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastResonanceSyncPulse(bool bSyncAchieved, float DamageMultiplier);
};
