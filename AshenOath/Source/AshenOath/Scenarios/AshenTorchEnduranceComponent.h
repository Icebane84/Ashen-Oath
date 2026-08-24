// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenTorchEnduranceComponent.generated.h"

/**
 * UAshenTorchEnduranceComponent
 * 
 * Manages torch fuel depletion over 120 seconds, rekindling with resin resources, and flare triggering.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTorchEnduranceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTorchEnduranceComponent();

	/** Consumes fuel over delta time and returns remaining fuel percentage [0.0 to 1.0] */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario8|Torch")
	float ConsumeTorchFuel(float DeltaSeconds);

	/** Adds resin to restore torch fuel */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario8|Torch")
	void RekindleTorch(float ResinFuelPercent);

	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario8|Torch")
	float GetCurrentFuel01() const { return CurrentFuel01; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8|Torch")
	float CurrentFuel01 = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario8|Torch")
	float TotalBurnDurationSeconds = 120.0f;
};
