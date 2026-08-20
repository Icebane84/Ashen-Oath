// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenBlackwoodBridgeLevelManagerActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBridgeCollapseTriggeredSignature, FName, ActivePhaseTag, float, StructuralIntegrityPercent);

/**
 * AAshenBlackwoodBridgeLevelManagerActor
 *
 * Level manager orchestrating the collapse and dynamic geometry of Blackwood Bridge (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenBlackwoodBridgeLevelManagerActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenBlackwoodBridgeLevelManagerActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BlackwoodBridge")
	void TriggerBridgeCollapsePhase(FName CollapsePhaseTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BlackwoodBridge|Events")
	FOnBridgeCollapseTriggeredSignature OnBridgeCollapseTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BlackwoodBridge")
	float StructuralIntegrityPercent = 100.0f;
};
