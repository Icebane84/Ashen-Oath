// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenVeilHoundAmbushSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVeilHoundAmbushTriggeredSignature, int32, PackCount, float, AmbushIntensity);

/**
 * UAshenVeilHoundAmbushSubsystem
 *
 * World Subsystem managing phase-shifting Veil Hound ambush wave spawns.
 */
UCLASS()
class ASHENOATH_API UAshenVeilHoundAmbushSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VeilHound")
	void TriggerVeilHoundAmbushPack(int32 PackCount, float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VeilHound|Events")
	FOnVeilHoundAmbushTriggeredSignature OnAmbushTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VeilHound")
	int32 TotalAmbushesSpawned = 0;
};
