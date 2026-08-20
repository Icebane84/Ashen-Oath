// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonPressurePlateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPressurePlateStateChangedSignature, FName, PlateID, bool, bIsDepressed);

/**
 * UAshenDungeonPressurePlateComponent
 *
 * Dungeon pressure plate floor puzzle component managing weight detection and sequence events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonPressurePlateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonPressurePlateComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|PressurePlate")
	void OnActorSteppedOn(AActor* SteppingActor);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PressurePlate")
	void OnActorSteppedOff(AActor* SteppingActor);

	UFUNCTION(BlueprintPure, Category = "AshenOath|PressurePlate")
	bool IsDepressed() const { return bIsDepressed; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|PressurePlate")
	FName PlateID = FName("Plate_01");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PressurePlate|Events")
	FOnPressurePlateStateChangedSignature OnPlateStateChanged;

private:
	bool bIsDepressed = false;
	int32 OverlappingActorCount = 0;
};
