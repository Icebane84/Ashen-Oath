// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenShepherdsGambitMasterBridge.generated.h"

/**
 * UAshenShepherdsGambitMasterBridge
 * Master domain bridge linking unchained state transitions, companion containment trees, and vital reserve draining.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShepherdsGambitMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShepherdsGambitMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bGambitBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastContainmentStatus(EContainmentState State);
};
