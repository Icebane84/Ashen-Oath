// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCombatEnvironmentalImpactSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEnvironmentalImpactTriggeredSignature, FVector, ImpactLocation, float, ImpactRadius, float, DebrisPoiseDamage);

/**
 * UAshenCombatEnvironmentalImpactSubsystem
 *
 * World Subsystem projecting heavy combat impacts into 3 layers:
 * Layer 1 (Combat): Debris poise damage in radius.
 * Layer 2 (VFX/Audio): Ground fracture decals & shockwave MetaSound.
 * Layer 3 (World): Regional corruption spread acceleration.
 */
UCLASS()
class ASHENOATH_API UAshenCombatEnvironmentalImpactSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ImpactSubsystem")
	void RegisterHeavyCombatImpact(FVector Location, float Radius, float PoiseDamage);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ImpactSubsystem|Events")
	FOnEnvironmentalImpactTriggeredSignature OnImpactTriggered;
};
