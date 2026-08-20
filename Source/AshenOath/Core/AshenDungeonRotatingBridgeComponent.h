// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonRotatingBridgeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBridgeRotatedSignature, float, NewAngle, bool, bIsAligned);

/**
 * UAshenDungeonRotatingBridgeComponent
 *
 * Interactive dungeon rotating bridge component managing rotational interps and alignment events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonRotatingBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonRotatingBridgeComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Bridge")
	bool RotateBridge(float TargetAngleStep = 90.0f);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Bridge")
	float GetCurrentAngle() const { return CurrentAngle; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Bridge")
	bool IsAligned() const { return bIsAligned; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Bridge")
	float TargetAlignedAngle = 180.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Bridge|Events")
	FOnBridgeRotatedSignature OnBridgeRotated;

private:
	float CurrentAngle = 0.0f;
	bool bIsAligned = false;
};
