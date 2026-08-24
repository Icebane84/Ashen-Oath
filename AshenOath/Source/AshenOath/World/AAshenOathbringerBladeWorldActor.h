// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AAshenOathbringerBladeWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenOathbringerBladeWorldActor
 * 
 * Spatial world actor representing the greatsword Oathbringer with sockets for garnet pommel eyes and kinetic impact physics.
 */
UCLASS()
class ASHENOATH_API AAshenOathbringerBladeWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathbringerBladeWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|World")
	float GetBladeLengthUU() const { return BladeLengthUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BladeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade")
	float BladeLengthUU = 180.0f;
};
