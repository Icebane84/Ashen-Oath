// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "UBTService_AshenAIWeatherAwareness.generated.h"

/**
 * UBTService_AshenAIWeatherAwareness
 * 
 * AI Behavior Tree service instructing companions and enemy factions to seek environmental shelter during catastrophic storm surges.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIWeatherAwareness : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIWeatherAwareness();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Weather")
	float MaxShelterSearchRadiusUU = 1500.0f;
};
