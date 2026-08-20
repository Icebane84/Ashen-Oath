// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalEcologyMasterBridge.generated.h"

/**
 * UAshenAlchemicalEcologyMasterBridge
 * Master bridge broadcasting lantern and ecological events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalEcologyMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalEcologyMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bEcologyBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastAlchemicalEventPulse(FName EventName, float Level);
};
