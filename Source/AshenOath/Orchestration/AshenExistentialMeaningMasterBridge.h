// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenExistentialMeaningMasterBridge.generated.h"

/**
 * UAshenExistentialMeaningMasterBridge
 * Master domain bridge linking Trial of Will stagger choices, Keystone Memory compilations, and Adaptive Trigger hardware resistance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenExistentialMeaningMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenExistentialMeaningMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bMeaningBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastTrialOfWillResolved(ETrialOfWillChoice Choice);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastKeystoneMemoryCompiled(FName MemoryID, EKeystoneInterpretiveLens Lens);
};
