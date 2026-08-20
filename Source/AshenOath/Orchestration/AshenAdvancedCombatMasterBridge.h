// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAdvancedCombatMasterBridge.generated.h"

/**
 * UAshenAdvancedCombatMasterBridge
 * Master bridge broadcasting advanced combat events across domain adapters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdvancedCombatMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAdvancedCombatMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bCombatBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastAdvancedCombatPulse(FName EventName, float Magnitude);
};
