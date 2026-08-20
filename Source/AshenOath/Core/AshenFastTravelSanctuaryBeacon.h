// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFastTravelSanctuaryBeacon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryBeaconActivatedSignature, FName, BeaconID, FVector, Location);

/**
 * UAshenFastTravelSanctuaryBeacon
 *
 * Sanctuary beacon component attached to sanctuary campfire actors.
 * Manages activation state and registers sanctuary position with UAshenFastTravelSubsystem.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFastTravelSanctuaryBeacon : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFastTravelSanctuaryBeacon();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuaryBeacon")
	void ActivateBeacon();

	UFUNCTION(BlueprintPure, Category = "AshenOath|SanctuaryBeacon")
	bool IsActivated() const { return bIsActivated; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanctuaryBeacon")
	FName SanctuaryID = FName("Sanctuary_Default");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuaryBeacon|Events")
	FOnSanctuaryBeaconActivatedSignature OnBeaconActivated;

private:
	bool bIsActivated = false;
};
