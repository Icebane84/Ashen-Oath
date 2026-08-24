// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AAshenDestructiblePillarActor.generated.h"

class UBoxComponent;

/**
 * AAshenDestructiblePillarActor
 * 
 * World actor representing a destructible architectural pillar that fractures under kinetic impacts and spawns dynamic navmesh obstacles.
 */
UCLASS()
class ASHENOATH_API AAshenDestructiblePillarActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenDestructiblePillarActor();

	virtual void BeginPlay() override;

	/** Applies structural kinetic impact to the pillar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Chaos")
	void ApplyStructuralImpact(float ImpactJoules);

	UFUNCTION(BlueprintPure, Category = "Ashen|Chaos")
	EChaosFractureSeverity GetCurrentFractureSeverity() const { return CurrentSeverity; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PillarMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* NavmeshObstacleBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	EStructuralMaterialType MaterialType = EStructuralMaterialType::GraniteStone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Chaos")
	EChaosFractureSeverity CurrentSeverity = EChaosFractureSeverity::IntactSolid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	float StructuralHealthJoules = 6000.0f;
};
