// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenOakhavenChapelRitualAltarWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenOakhavenChapelRitualAltarWorldActor
 * 
 * Interactive altar actor in Oakhaven Chapel where Kaelen channels Clarity of Heart.
 */
UCLASS()
class ASHENOATH_API AAshenOakhavenChapelRitualAltarWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOakhavenChapelRitualAltarWorldActor();

	virtual void BeginPlay() override;

	/** Begins the purification ritual at this altar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario1")
	void InitiateRitual();

	/** Interrupts the ritual due to Malakor's attack */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario1")
	void BreakRitual();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario1")
	bool IsRitualActive() const { return bRitualActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AltarMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AmberBrazierMesh;

private:
	bool bRitualActive = false;
};
