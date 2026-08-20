// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenControllerFrictionMasterBridge.generated.h"

/**
 * UAshenControllerFrictionMasterBridge
 * Master domain bridge orchestrating controller friction, struggle phases, and GAS ability activation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerFrictionMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenControllerFrictionMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bFrictionBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastStrugglePhaseResolved(EStrugglePhase Phase, bool bSuccess);
};
