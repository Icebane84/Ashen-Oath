// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCANGlassShieldProtocolComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlassShieldDeployedSignature, float, BarrierStrength, bool, bWillFractureOnImpact);

/**
 * UAshenCANGlassShieldProtocolComponent
 *
 * Component evaluating Serafina's Glass Shield Protocol CAN anchor (can-glass_shield_protocol).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCANGlassShieldProtocolComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCANGlassShieldProtocolComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void DeployGlassShield(float BaseStrength);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnGlassShieldDeployedSignature OnGlassShieldDeployed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	float ActiveGlassShieldHealth = 0.0f;
};
