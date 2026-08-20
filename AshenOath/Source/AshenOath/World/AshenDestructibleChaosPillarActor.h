// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenDestructibleChaosPillarActor.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;

/**
 * AAshenDestructibleChaosPillarActor
 * 
 * 3D world destructible stone pillar entity that fractures and shatters
 * into physical Chaos rubble when struck by high-kinetic cleaves (> 4500 Joules).
 */
UCLASS()
class ASHENOATH_API AAshenDestructibleChaosPillarActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenDestructibleChaosPillarActor();

	virtual void BeginPlay() override;

	/** Applies kinetic strike impact to the pillar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Chaos")
	EStructuralFractureTier ApplyKineticImpact(float KineticEnergyJoules, const FVector& ImpactPoint);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Chaos")
	bool IsPillarFractured() const { return bIsFractured; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Chaos")
	float GetStructuralIntegrity() const { return CurrentIntegrityJoules; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* StructuralCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PillarMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Chaos")
	float MaxIntegrityJoules = 4500.0f;

private:
	float CurrentIntegrityJoules = 4500.0f;
	bool bIsFractured = false;
};
