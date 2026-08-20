// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCompanionTacticalCoverSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTacticalCoverAssignedSignature, FName, CompanionID, FVector, CoverLocation);

/**
 * UAshenCompanionTacticalCoverSubsystem
 *
 * World Subsystem driving Garrett & Serafina's tactical cover selection and line-of-sight flanking routines.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionTacticalCoverSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TacticalCover")
	FVector FindOptimalTacticalCover(FName CompanionID, FVector OriginLocation, float MaxSearchRadius = 1200.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TacticalCover|Events")
	FOnTacticalCoverAssignedSignature OnCoverAssigned;
};
