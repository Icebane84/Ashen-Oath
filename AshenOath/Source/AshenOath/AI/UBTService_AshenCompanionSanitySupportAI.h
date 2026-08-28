// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "UBTService_AshenCompanionSanitySupportAI.generated.h"

/**
 * UBTService_AshenCompanionSanitySupportAI
 * 
 * AI Behavior Tree service monitoring wielder sanity and dispatching companion triage reactions (Garrett smelling salts, Serafina radiant dome).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCompanionSanitySupportAI : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCompanionSanitySupportAI();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Sanity")
	float CriticalSanityThreshold = 35.0f;
};
