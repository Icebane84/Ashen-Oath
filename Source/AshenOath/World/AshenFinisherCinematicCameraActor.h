// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenFinisherCinematicCameraActor.generated.h"

/**
 * AAshenFinisherCinematicCameraActor
 * World camera actor framing cinematic slow-motion execution flourishes.
 */
UCLASS()
class ASHENOATH_API AAshenFinisherCinematicCameraActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenFinisherCinematicCameraActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void FrameFinisherCinematic(FVector TargetLocation, float Duration);
};
