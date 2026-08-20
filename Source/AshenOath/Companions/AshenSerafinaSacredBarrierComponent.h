// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaSacredBarrierComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSacredBarrierDeployedSignature, FVector, BarrierLocation, float, MaxAbsorbedDamage);

/**
 * UAshenSerafinaSacredBarrierComponent
 *
 * Hard-light holy barrier absorbing projectile fire and shielding Kaelen and Garrett (PRS-001 Serafina Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSacredBarrierComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaSacredBarrierComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaBarrier")
	void DeploySacredBarrier(FVector Location, float BarrierHealth = 1000.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaBarrier|Events")
	FOnSacredBarrierDeployedSignature OnSacredBarrierDeployed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaBarrier")
	bool bIsBarrierActive = false;
};
