// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenBlackwoodBridgeGateVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBridgeGateUpdatedSignature, bool, bIsGateOpen, float, OpenAngleDegrees);

/**
 * AAshenBlackwoodBridgeGateVisualLocusActor
 *
 * World Actor rendering the ancient iron gate loci of Blackwood Bridge (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenBlackwoodBridgeGateVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenBlackwoodBridgeGateVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BridgeGate")
	void SetGateState(bool bOpen);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BridgeGate|Events")
	FOnBridgeGateUpdatedSignature OnGateUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BridgeGate")
	bool bIsGateOpen = false;
};
