// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "Combat/AshenSeveranceTypes.h"
#include "UBTService_AshenAIPanicOnSeveranceWitness.generated.h"

/**
 * UBTService_AshenAIPanicOnSeveranceWitness
 * 
 * Enemy AI service detecting nearby severed allies within 800uu, inducing morale fracture (panic state / defensive retreat).
 */
UCLASS()
class ASHENOATH_API UBTService_AshenAIPanicOnSeveranceWitness : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_AshenAIPanicOnSeveranceWitness();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Severance")
	float PanicWitnessRadiusUU = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AI|Severance")
	bool bInPanickedState = false;
};
