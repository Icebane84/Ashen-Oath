// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenCampfireCookingTypes.h"
#include "UBTService_AshenCompanionCampfireSocialAI.generated.h"

/**
 * UBTService_AshenCompanionCampfireSocialAI
 * 
 * AI Behavior Tree service controlling companion idle positioning around the campfire, eating animations, and conversational triggers.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenCompanionCampfireSocialAI : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenCompanionCampfireSocialAI();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Campfire")
	float CampfireSocialRadiusUU = 250.0f;
};
