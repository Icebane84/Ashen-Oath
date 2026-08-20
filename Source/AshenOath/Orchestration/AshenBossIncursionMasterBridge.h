// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossIncursionMasterBridge.generated.h"

/**
 * UAshenBossIncursionMasterBridge
 * Master domain bridge linking Boss state machines with Trio GAS abilities, HUD widgets, and audio triggers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossIncursionMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossIncursionMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bBossBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastBossPhaseTransition(EBossPhaseState NewPhase);
};
