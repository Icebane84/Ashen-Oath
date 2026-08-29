// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AAshenAlchemicalCoatingCrucibleWorldActor.generated.h"

/**
 * AAshenAlchemicalCoatingCrucibleWorldActor
 * 
 * Interactive campfire cauldron crucible world actor where Garrett brews alchemical flasks and Kaelen polishes Oathbringer to cleanse soot.
 */
UCLASS()
class ASHENOATH_API AAshenAlchemicalCoatingCrucibleWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenAlchemicalCoatingCrucibleWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Crucible")
	void BrewFlask(EAlchemicalBladeCoating Coating, int32 Quantity);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Crucible")
	int32 GetTotalFlasksBrewed() const { return TotalFlasksBrewed; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Crucible")
	int32 TotalFlasksBrewed = 0;
};
