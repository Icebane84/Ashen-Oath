// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "UBTService_AshenCompanionTraumaWatch.generated.h"

/**
 * UBTService_AshenCompanionTraumaWatch
 * 
 * Behavior Tree service allowing companions to visually detect Kaelen's vein corruption stage and dynamically shift formation distance.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCompanionTraumaWatch : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCompanionTraumaWatch();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Somatics")
	float CrisisThreshold = 0.50f;
};
