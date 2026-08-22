// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AAshenVolatileGasPocketWorldActor.generated.h"

class USphereComponent;
class UParticleSystemComponent;

/**
 * AAshenVolatileGasPocketWorldActor
 * 
 * Flammable swamp gas pocket actor detonating upon taking fire damage.
 */
UCLASS()
class ASHENOATH_API AAshenVolatileGasPocketWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenVolatileGasPocketWorldActor();

	virtual void BeginPlay() override;

	/** Detonates the gas pocket */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario5")
	void DetonateGasPocket(float BlastRadiusCentimeters);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario5")
	bool HasDetonated() const { return bHasDetonated; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* TriggerSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario5")
	float BlastDamage = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario5")
	float BlastRadiusCentimeters = 450.0f;

private:
	bool bHasDetonated = false;
};
