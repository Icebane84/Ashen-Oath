// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDualityTransformationLocusActor.generated.h"

/**
 * AAshenDualityTransformationLocusActor
 * Physical world locus actor providing transformation threshold environmental lighting & particle FX anchors.
 */
UCLASS()
class ASHENOATH_API AAshenDualityTransformationLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenDualityTransformationLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Duality")
	float TransformationLocusRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Duality")
	bool TriggerDualityTransformationAuraPulse();
};
