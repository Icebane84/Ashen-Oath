// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AAshenWaystationCourtyardAnchorActor.generated.h"

class UBoxComponent;

/**
 * AAshenWaystationCourtyardAnchorActor
 * 
 * Spatial boundary anchor defining the shattered Heartstone waystation courtyard container.
 */
UCLASS()
class ASHENOATH_API AAshenWaystationCourtyardAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWaystationCourtyardAnchorActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Waystation")
	float GetCourtyardRadiusCentimeters() const { return CourtyardRadiusCentimeters; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* CourtyardBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Waystation")
	float CourtyardRadiusCentimeters = 1500.0f;
};
