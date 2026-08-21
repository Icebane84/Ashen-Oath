// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenDualSenseMasterBridge.generated.h"

/**
 * UAshenDualSenseMasterBridge
 * 
 * Master orchestrator unifying DualSense adaptive trigger priority,
 * directional threat rumble, and controller speaker whisper routing.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualSenseMasterBridge();

	/** Broadcasts a trigger lockout change */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Haptics")
	void BroadcastTriggerLockout(bool bEngaged);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Haptics")
	FOnTriggerLockoutEngaged OnTriggerLockoutEngaged;
};
