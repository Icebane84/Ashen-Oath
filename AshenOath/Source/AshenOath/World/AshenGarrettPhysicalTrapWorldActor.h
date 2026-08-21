// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenGarrettPhysicalTrapWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenGarrettPhysicalTrapWorldActor
 * 
 * Physicalized world trap placed by Garrett in the Spire of Elders corridors.
 */
UCLASS()
class ASHENOATH_API AAshenGarrettPhysicalTrapWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenGarrettPhysicalTrapWorldActor();

	virtual void BeginPlay() override;

	/** Arms the physical trap */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario2")
	void ArmTrap(EGarrettTrapType InType, float InRadius);

	/** Detonates the trap upon enemy overlap */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario2")
	void DetonateTrap();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario2")
	bool IsArmed() const { return bIsArmed; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* TrapMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario2")
	EGarrettTrapType TrapType = EGarrettTrapType::TensionWireSnare;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario2")
	float DetonationRadiusCentimeters = 350.0f;

private:
	bool bIsArmed = false;
	bool bHasDetonated = false;
};
