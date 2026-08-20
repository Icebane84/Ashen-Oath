// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAbominationBossPhaseSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbominationVoidPhaseTriggeredSignature, int32, PhaseTier, float, VoidSmotherIntensity);

/**
 * UAshenAbominationBossPhaseSubsystem
 *
 * Subsystem driving Abomination Void Smothering enrage phases.
 */
UCLASS()
class ASHENOATH_API UAshenAbominationBossPhaseSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AbominationPhase")
	void TriggerAbominationVoidPhase(int32 PhaseTier, float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AbominationPhase|Events")
	FOnAbominationVoidPhaseTriggeredSignature OnVoidPhaseTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AbominationPhase")
	int32 ActivePhaseTier = 1;
};
