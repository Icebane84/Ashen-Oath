// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "BTTask_AshenEmitCompanionHapticCue.generated.h"

/**
 * UBTTask_AshenEmitCompanionHapticCue
 * 
 * Behavior Tree Task triggering a directional haptic tick and controller speaker whisper.
 */
UCLASS()
class ASHENOATH_API UBTTask_AshenEmitCompanionHapticCue : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AshenEmitCompanionHapticCue();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Haptics")
	ETactileWhisperChannel Channel = ETactileWhisperChannel::GarrettTactical;
};
