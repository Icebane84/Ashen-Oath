// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAegisBarrierComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAegisBarrierDeployedSignature, float, BarrierStrength, float, AbsorptionPercent);

/**
 * UAshenAegisBarrierComponent
 *
 * Component creating Serafina's radiant Aegis shield barrier against dark magic.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAegisBarrierComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAegisBarrierComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisBarrier")
	void DeployAegisBarrier(float Strength = 250.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisBarrier|Events")
	FOnAegisBarrierDeployedSignature OnBarrierDeployed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisBarrier")
	bool bIsBarrierActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisBarrier")
	float ActiveBarrierStrength = 0.0f;
};
