// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceDismembermentConvergenceSubsystem.generated.h"

/**
 * UAshenSeveranceDismembermentConvergenceSubsystem
 * 
 * Central world subsystem coordinating dynamic skeletal mesh severance, ragdoll gib spawning, blood splatter decal pooling, and somatic adrenaline buffs.
 */
UCLASS()
class ASHENOATH_API UAshenSeveranceDismembermentConvergenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSeveranceDismembermentConvergenceSubsystem();

	/** Executes a dismemberment slice on a target actor */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Severance")
	FSeveranceDismembermentResult ExecuteSeverance(AActor* TargetActor, ESeveranceBoneTarget BoneTarget, const FSeveranceSlicePlaneData& SlicePlane);

	/** Adds adrenaline to the active surge pool */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Severance")
	void AddAdrenaline(float Amount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Severance")
	float GetCurrentAdrenaline() const { return AdrenalineState.CurrentAdrenaline; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Severance")
	bool IsHyperArmorActive() const { return AdrenalineState.bHyperArmorActive; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Severance")
	FOnSeveranceExecuted OnSeveranceExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Severance")
	FOnAdrenalineSurgeTriggered OnAdrenalineSurgeTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Severance")
	FOnBloodSplatterSpawned OnBloodSplatterSpawned;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Severance")
	FOnNearbyAIWitnessedExecution OnNearbyAIWitnessedExecution;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Severance")
	FAdrenalineSurgeState AdrenalineState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Severance")
	int32 MaxActiveGibs = 16;
};
