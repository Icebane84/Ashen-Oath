// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenWeaponSootAccumulationComponent.generated.h"

/**
 * UAshenWeaponSootAccumulationComponent
 * 
 * Tracks cumulative kinetic energy (Joules) deposited into the weapon and maps it to procedural soot and edge micro-nicks.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponSootAccumulationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponSootAccumulationComponent();

	/** Records strike kinetic energy and updates soot and nick metrics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Soot")
	void RecordStrikeEnergy(float Joules);

	/** Wipes soot from blade */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Soot")
	void CleanBlade();

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Soot")
	float GetBladeSootScalar() const { return BladeSootScalar; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Soot")
	float GetCumulativeJoules() const { return CumulativeStrikeJoules; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Soot")
	int32 GetMicroNickCount() const { return MicroNickCount; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	float BladeSootScalar = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	float CumulativeStrikeJoules = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	int32 MicroNickCount = 0;
};
