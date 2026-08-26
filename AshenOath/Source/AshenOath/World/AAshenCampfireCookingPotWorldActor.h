// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AAshenCampfireCookingPotWorldActor.generated.h"

/**
 * AAshenCampfireCookingPotWorldActor
 * 
 * Spatial world actor representing the iron campfire cauldron with tripod stand, simmering steam VFX, and interactive ladle socket.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireCookingPotWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireCookingPotWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Cooking")
	float GetPotCapacityLiters() const { return PotCapacityLiters; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	float PotCapacityLiters = 8.0f;
};
