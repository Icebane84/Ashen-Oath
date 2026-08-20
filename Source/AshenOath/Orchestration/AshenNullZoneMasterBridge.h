// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNullZoneMasterBridge.generated.h"

/**
 * UAshenNullZoneMasterBridge
 * Master bridge broadcasting Null Zone environmental events across domain subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNullZoneMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNullZoneMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bNullZoneBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastNullZoneTransition(bool bEntered, float DrainRate);
};
