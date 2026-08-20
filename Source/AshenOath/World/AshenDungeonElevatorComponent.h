// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonElevatorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnElevatorFloorReachedSignature, int32, TargetFloor, FVector, FloorLocation);

/**
 * UAshenDungeonElevatorComponent
 *
 * Interactive dungeon elevator component managing multi-floor destination stops and smooth ascent/descent.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonElevatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonElevatorComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Elevator")
	bool MoveToFloor(int32 TargetFloorIndex);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Elevator")
	int32 GetCurrentFloor() const { return CurrentFloor; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Elevator")
	bool IsMoving() const { return bIsMoving; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Elevator")
	int32 TotalFloors = 3;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Elevator|Events")
	FOnElevatorFloorReachedSignature OnFloorReached;

private:
	int32 CurrentFloor = 0;
	bool bIsMoving = false;
};
