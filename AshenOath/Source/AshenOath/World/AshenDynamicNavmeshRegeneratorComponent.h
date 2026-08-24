// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenDynamicNavmeshRegeneratorComponent.generated.h"

/**
 * UAshenDynamicNavmeshRegeneratorComponent
 * 
 * Instructs the navigation system to dynamically carve or rebuild local navmesh tiles around fractured debris.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDynamicNavmeshRegeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDynamicNavmeshRegeneratorComponent();

	/** Triggers dynamic navmesh tile rebuild in the specified radius */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Chaos|Navmesh")
	bool RequestNavmeshTileRebuild(const FVector& Origin, float RadiusUU);
};
