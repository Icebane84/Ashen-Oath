// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSpiritualStainSanctuaryCleanser.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSanctuaryCleanseExecutedSignature, int32, ResourcesConsumed, float, CleansePercentAmount, float, RemainingStainPercent);

/**
 * UAshenSpiritualStainSanctuaryCleanser
 *
 * Cleanser consuming rare sanctuary resources to wash away black UI Health Stain (The Cost / Spiritual Scarring, PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenSpiritualStainSanctuaryCleanser : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuaryCleanser")
	bool CleanseStainAtSanctuary(float CurrentStainPercent, int32 AvailableSanctuaryResources);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuaryCleanser|Events")
	FOnSanctuaryCleanseExecutedSignature OnSanctuaryCleanseExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SanctuaryCleanser")
	int32 TotalCleansesExecuted = 0;
};
