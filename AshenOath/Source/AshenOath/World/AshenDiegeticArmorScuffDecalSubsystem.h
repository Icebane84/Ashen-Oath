// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDiegeticArmorScuffDecalSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArmorScuffAppliedSignature, AActor*, TargetActor, float, ScuffSeverityPercent);

/**
 * UAshenDiegeticArmorScuffDecalSubsystem
 *
 * World Subsystem projecting armor scrape decals, scratch parameters, and metallic impact ringing onto character skeletal meshes.
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticArmorScuffDecalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ArmorScuff")
	void ApplyArmorScuffImpact(AActor* TargetActor, float DamageAmount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ArmorScuff|Events")
	FOnArmorScuffAppliedSignature OnArmorScuffApplied;
};
