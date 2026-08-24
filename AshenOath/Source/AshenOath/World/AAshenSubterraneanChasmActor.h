// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AAshenSubterraneanChasmActor.generated.h"

class UBoxComponent;

/**
 * AAshenSubterraneanChasmActor
 * 
 * Spatial world actor in the subterranean catacombs representing lethal chasm drop-offs and echo bounce boundaries.
 */
UCLASS()
class ASHENOATH_API AAshenSubterraneanChasmActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSubterraneanChasmActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|World")
	float GetChasmDropDepthUU() const { return ChasmDropDepthUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* ChasmBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8")
	float ChasmDropDepthUU = 2500.0f;
};
