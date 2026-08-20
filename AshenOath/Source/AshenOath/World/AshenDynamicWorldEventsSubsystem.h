// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDynamicWorldEventsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWorldEventTriggeredSignature, FName, EventID, float, EventThreatLevel);

/**
 * UAshenDynamicWorldEventsSubsystem
 *
 * World Subsystem spawning dynamic world events (Void incursions, Order patrols, ash storms) driven by global Taint.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicWorldEventsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WorldEvents")
	void TriggerDynamicWorldEvent(FName EventID, float GlobalTaintLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WorldEvents|Events")
	FOnWorldEventTriggeredSignature OnWorldEventTriggered;
};
