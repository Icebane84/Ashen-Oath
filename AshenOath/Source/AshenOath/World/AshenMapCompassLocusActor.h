// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMapCompassLocusActor.generated.h"

/**
 * AAshenMapCompassLocusActor
 * Interactive world actor providing cardinal orientation alignment and spatial map coordinate telemetry.
 */
UCLASS()
class ASHENOATH_API AAshenMapCompassLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMapCompassLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Map")
	float CompassOrientationYaw = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map")
	FVector2D GetNormalizedMapCoordinates() const;
};
