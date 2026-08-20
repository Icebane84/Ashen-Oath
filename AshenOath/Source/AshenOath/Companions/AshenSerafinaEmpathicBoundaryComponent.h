// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSerafinaEmpathicBoundaryComponent.generated.h"

/**
 * UAshenSerafinaEmpathicBoundaryComponent
 * 
 * Manages Serafina's spiritual boundaries and empathy actions:
 * - Empathic Transference: Absorbs Kaelen's dysregulation, accumulating physical soot and fever
 * - Crisis Consecrated Circle: Consecrates the ground at Kaelen's feet during extreme panic
 *   if historical repair weight justifies radical vulnerability.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaEmpathicBoundaryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaEmpathicBoundaryComponent();

	/** Evaluates whether Serafina will cast a Consecrated Circle under extreme crisis */
	UFUNCTION(BlueprintPure, Category = "Ashen|Serafina|Empathy")
	bool ShouldCastCrisisSanctuary(
		float TrustSerafina,
		float KaelenInternalFriction,
		float ActiveRepairVelocity) const;

	/** Computes net transference absorption capacity before burnout lockout */
	UFUNCTION(BlueprintPure, Category = "Ashen|Serafina|Empathy")
	float CalculateTransferenceCapacity(float BurnoutSerafina, float TrustSerafina) const;

	/** Applies transference toll and returns resulting residual soot scalar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Serafina|Empathy")
	float ApplyTransferenceToll(float AbsorbedDysregulation);

	UFUNCTION(BlueprintPure, Category = "Ashen|Serafina|Empathy")
	float GetAccumulatedSoot() const { return CurrentAccumulatedSoot; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Serafina|Empathy")
	float MaxSafeAbsorptionToll = 0.60f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Serafina|Empathy")
	float SootDecayRatePerSecond = 0.05f;

private:
	float CurrentAccumulatedSoot = 0.0f;
};
