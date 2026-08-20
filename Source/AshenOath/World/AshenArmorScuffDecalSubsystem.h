// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenArmorScuffDecalSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArmorDecalScuffAppliedSignature, AActor*, TargetActor, float, DamageWearAmount);

/**
 * UAshenArmorScuffDecalSubsystem
 *
 * World Subsystem projecting diegetic scuff & wear decals onto armor meshes.
 */
UCLASS()
class ASHENOATH_API UAshenArmorScuffDecalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ArmorScuff")
	void ProjectArmorScuffDecal(AActor* TargetActor, float DamageWearAmount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ArmorScuff|Events")
	FOnArmorDecalScuffAppliedSignature OnArmorScuffApplied;
};
