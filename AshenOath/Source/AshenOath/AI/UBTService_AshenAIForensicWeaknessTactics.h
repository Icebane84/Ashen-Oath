// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "UBTService_AshenAIForensicWeaknessTactics.generated.h"

/**
 * UBTService_AshenAIForensicWeaknessTactics
 * 
 * Companion and player tactical AI service adjusting combat targeting toward solved anatomical weak points (e.g. severing tendons, puncturing venom glands).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIForensicWeaknessTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIForensicWeaknessTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Forensic")
	bool bTargetingVulnerableGland = false;
};
