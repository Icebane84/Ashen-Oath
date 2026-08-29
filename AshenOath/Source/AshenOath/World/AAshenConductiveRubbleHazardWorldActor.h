// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AAshenConductiveRubbleHazardWorldActor.generated.h"

/**
 * AAshenConductiveRubbleHazardWorldActor
 * 
 * Interactive world actor representing a metallic rubble or wet puddle cluster that acts as a conductive medium for lightning chain reactions.
 */
UCLASS()
class ASHENOATH_API AAshenConductiveRubbleHazardWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenConductiveRubbleHazardWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Convergence")
	EConductiveSurfaceType GetConductiveType() const { return SurfaceType; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Convergence")
	float GetConductionRadiusUU() const { return ConductionRadiusUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Convergence")
	EConductiveSurfaceType SurfaceType = EConductiveSurfaceType::MetallicIronRubble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Convergence")
	float ConductionRadiusUU = 350.0f;
};
