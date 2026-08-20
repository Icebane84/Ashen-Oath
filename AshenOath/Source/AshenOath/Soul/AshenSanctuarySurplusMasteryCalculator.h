// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSanctuarySurplusMasteryCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuarySurplusCalculatedSignature, int32, SavedSanctuaryResources, float, ResonanceTuningMultiplier);

/**
 * UAshenSanctuarySurplusMasteryCalculator
 *
 * Calculator tracking resource savings from avoiding spiritual scarring for Resonance Tuning (Long-Term Mastery).
 */
UCLASS()
class ASHENOATH_API UAshenSanctuarySurplusMasteryCalculator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuarySurplus")
	int32 CalculateSanctuarySurplus(float CurrentStainPercent, int32 TotalQuestsCompleted);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuarySurplus|Events")
	FOnSanctuarySurplusCalculatedSignature OnSurplusCalculated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SanctuarySurplus")
	int32 ActiveSavedResources = 0;
};
