// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AAshenZenithApexAltarActor.generated.h"

class UBoxComponent;

/**
 * AAshenZenithApexAltarActor
 * 
 * Spatial world actor in Scenario 10 representing the Grand Zenith apex altar where the final consequence resolution occurs.
 */
UCLASS()
class ASHENOATH_API AAshenZenithApexAltarActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenZenithApexAltarActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario10|World")
	float GetAltarRadiusUU() const { return AltarRadiusUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* AltarBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	float AltarRadiusUU = 1500.0f;
};
