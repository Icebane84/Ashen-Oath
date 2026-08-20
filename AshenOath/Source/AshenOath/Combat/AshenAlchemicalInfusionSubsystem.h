// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAlchemicalInfusionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAlchemicalInfusionAppliedSignature, FName, InfusionID, float, InfusionDuration);

/**
 * UAshenAlchemicalInfusionSubsystem
 *
 * Subsystem managing elemental potion & oil infusions for weapons.
 */
UCLASS()
class ASHENOATH_API UAshenAlchemicalInfusionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AlchemicalInfusion")
	void ApplyAlchemicalInfusion(FName InfusionID, float Duration = 30.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AlchemicalInfusion|Events")
	FOnAlchemicalInfusionAppliedSignature OnInfusionApplied;
};
