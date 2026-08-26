// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AAshenDestructibleMasonryWorldActor.generated.h"

/**
 * AAshenDestructibleMasonryWorldActor
 * 
 * Spatial Chaos world actor representing overhead archways and stone ramparts susceptible to structural fatigue and demolition.
 */
UCLASS()
class ASHENOATH_API AAshenDestructibleMasonryWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenDestructibleMasonryWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Rubble")
	float GetStructureDurability() const { return StructureDurability; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float StructureDurability = 1000.0f;
};
