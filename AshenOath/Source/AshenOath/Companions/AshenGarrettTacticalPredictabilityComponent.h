// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenGarrettTacticalPredictabilityComponent.generated.h"

/**
 * UAshenGarrettTacticalPredictabilityComponent
 * 
 * Drives Garrett's dynamic tactical spacing on the battlefield.
 * If Kaelen relies heavily on the dark parasite or behaves erratically,
 * Garrett expands spacing to 800.0uu for tactical self-preservation.
 * When cohesion is high, spacing tightens to 250.0uu for mutual protection.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalPredictabilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettTacticalPredictabilityComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Computes target follow distance for Garrett based on Kaelen's Internal Friction and Trust */
	UFUNCTION(BlueprintPure, Category = "Ashen|Garrett|Tactical")
	float CalculateTargetSpacing(float InternalFriction, float TrustGarrett, float FatigueGarrett) const;

	/** Evaluates whether Garrett is willing to take a high-risk flank setup */
	UFUNCTION(BlueprintPure, Category = "Ashen|Garrett|Tactical")
	bool CanExecuteRiskyFlank(float TrustGarrett, float ActiveRepairVelocity) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Garrett|Tactical")
	float GetCurrentSpacing() const { return CurrentSpacingUU; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Garrett|Tactical")
	float MinTightSpacingUU = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Garrett|Tactical")
	float MaxGuardedSpacingUU = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Garrett|Tactical")
	float SpacingInterpSpeed = 3.5f;

private:
	float CurrentSpacingUU = 400.0f;
	float TargetSpacingUU = 400.0f;
};
