// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenBridgeCollapseVFXAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBridgeCollapseVFXTriggeredSignature, FVector, CollapseCenter, float, DebrisVolumeScale);

/**
 * AAshenBridgeCollapseVFXAnchorActor
 *
 * World Actor anchoring debris and dust explosion particle/lighting FX during bridge collapse (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenBridgeCollapseVFXAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenBridgeCollapseVFXAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BridgeVFX")
	void TriggerBridgeCollapseVFX(float Scale = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BridgeVFX|Events")
	FOnBridgeCollapseVFXTriggeredSignature OnCollapseVFXTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BridgeVFX")
	bool bIsDebrisActive = false;
};
