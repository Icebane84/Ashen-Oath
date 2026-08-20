// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenConsecratedCircleActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCirclePulseSignature, FVector, CircleLocation, float, CurrentRadius);

/**
 * AAshenConsecratedCircleActor
 *
 * Actor deploying Serafina's radiant consecrated ward circle healing allies and burning corrupt foes.
 */
UCLASS()
class ASHENOATH_API AAshenConsecratedCircleActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenConsecratedCircleActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConsecratedCircle")
	void PulseConsecratedCircle();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConsecratedCircle|Events")
	FOnCirclePulseSignature OnCirclePulse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ConsecratedCircle")
	float CircleRadius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ConsecratedCircle")
	float HealPerPulse = 80.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ConsecratedCircle")
	float BurnDamagePerPulse = 120.0f;
};
