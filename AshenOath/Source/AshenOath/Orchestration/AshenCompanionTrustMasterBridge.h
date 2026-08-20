// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustMasterBridge.generated.h"

/**
 * UAshenCompanionTrustMasterBridge
 * Master bridge orchestrating synchronization between trust subsystems and peripheral domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionTrustMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bTrustBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastTrustUpdatePulse(float GarrettTrust, float SerafinaTrust);
};
