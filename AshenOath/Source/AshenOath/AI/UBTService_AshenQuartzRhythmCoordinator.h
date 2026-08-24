// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "UBTService_AshenQuartzRhythmCoordinator.generated.h"

/**
 * UBTService_AshenQuartzRhythmCoordinator
 * 
 * AI Behavior Tree service synchronizing companion tactical decisions and combo triggers to the Quartz 115 BPM musical grid.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenQuartzRhythmCoordinator : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenQuartzRhythmCoordinator();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Quartz")
	float TargetBPM = 115.0f;
};
