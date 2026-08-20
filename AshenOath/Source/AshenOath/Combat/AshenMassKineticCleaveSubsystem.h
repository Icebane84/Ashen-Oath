// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenMassKineticCleaveSubsystem.generated.h"

class UAshenMassKineticCleaveComponent;
class UAshenWeaponResistanceWarperComponent;
class UAshenCameraResistanceDilationComponent;

/**
 * UAshenMassKineticCleaveSubsystem
 * 
 * Central world subsystem coordinating weapon kinetic energy calculations,
 * Chaos environmental structural fracture, and volume drag resistance warping.
 */
UCLASS()
class ASHENOATH_API UAshenMassKineticCleaveSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenMassKineticCleaveSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Calculates kinetic energy of a weapon swing */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Kinetic")
	FKineticSwingSnapshot EvaluateSwingKinetics(
		EKineticCleaveStance Stance,
		float BladeTipVelocityMetersPerSec);

	/** Calculates volume drag and animation slow down when cleaving matter */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Kinetic")
	FVolumeDragResult ProcessMatterVolumeDrag(float SubmergedVolumeCM3);

	/** Records structural destruction of environmental geometry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Kinetic")
	void RecordStructuralDestruction(const FVector& ImpactLocation, float EnergyJoules);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Kinetic")
	FOnKineticSwingCalculated OnKineticSwingCalculated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Kinetic")
	FOnVolumeDragUpdated OnVolumeDragUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat|Kinetic")
	FOnStructuralDestructionTriggered OnStructuralDestructionTriggered;

protected:
	UPROPERTY()
	UAshenMassKineticCleaveComponent* CleaveComponent;

	UPROPERTY()
	UAshenWeaponResistanceWarperComponent* WarperComponent;

	UPROPERTY()
	UAshenCameraResistanceDilationComponent* DilationComponent;
};
