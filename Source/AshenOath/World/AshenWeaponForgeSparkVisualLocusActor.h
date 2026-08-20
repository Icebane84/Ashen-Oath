// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWeaponForgeSparkVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnForgeSparksTriggeredSignature, FVector, AnvilLocation, float, SparkBurstIntensity);

/**
 * AAshenWeaponForgeSparkVisualLocusActor
 *
 * World Actor rendering anvil blacksmithing sparks and ember particle FX (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenWeaponForgeSparkVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWeaponForgeSparkVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ForgeSparks")
	void TriggerForgeSparkBurst(float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ForgeSparks|Events")
	FOnForgeSparksTriggeredSignature OnForgeSparksTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ForgeSparks")
	bool bIsSparksActive = false;
};
