// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AAshenMireMudSludgeVolumeActor.generated.h"

class UBoxComponent;

/**
 * AAshenMireMudSludgeVolumeActor
 * 
 * Environmental trigger volume applying deep mud friction penalties (0.50x speed) in the Weeping Mire.
 */
UCLASS()
class ASHENOATH_API AAshenMireMudSludgeVolumeActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMireMudSludgeVolumeActor();

	virtual void BeginPlay() override;

	/** Sets the mud sludge friction coefficient */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario5")
	void SetMudFriction(float NewFriction);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario5")
	float GetMudFriction() const { return MudFrictionCoefficient; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* VolumeBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario5")
	float MudFrictionCoefficient = 0.50f;
};
