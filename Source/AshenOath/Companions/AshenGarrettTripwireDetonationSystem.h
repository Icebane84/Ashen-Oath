// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenGarrettTripwireDetonationSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTripwireDetonatedSignature, FVector, DetonationLocation, float, StaggerPower, float, ArmorScuffAmount);

/**
 * UAshenGarrettTripwireDetonationSystem
 *
 * System placing and detonating environmental tripwires for heavy stagger and armor scuffing (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettTripwireDetonationSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettTripwire")
	void TriggerTripwireDetonation(FVector Location, float BaseStagger = 200.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettTripwire|Events")
	FOnTripwireDetonatedSignature OnTripwireDetonated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettTripwire")
	int32 TotalTripwiresDetonated = 0;
};
