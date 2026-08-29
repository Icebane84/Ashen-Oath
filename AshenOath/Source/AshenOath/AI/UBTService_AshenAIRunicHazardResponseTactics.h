// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "UBTService_AshenAIRunicHazardResponseTactics.generated.h"

/**
 * UBTService_AshenAIRunicHazardResponseTactics
 * 
 * Enemy AI service detecting active ground fissures (Vom Tag) and gravimetric pulls (Pflug/Mordhau), triggering evasive rolls and defensive guard recovery.
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIRunicHazardResponseTactics : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIRunicHazardResponseTactics();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|RunicForge")
	bool bEvadingTerrainFissure = false;
};
