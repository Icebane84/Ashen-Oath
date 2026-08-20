// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenHeartstoneSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeartstoneCrucibleForged, FName, TraitID, float, ReducedDebt);

/**
 * UAshenHeartstoneSubsystem
 * Subsystem managing soul remnant alchemy, heartstone memory forging, and integration debt clearing.
 */
UCLASS()
class ASHENOATH_API UAshenHeartstoneSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Heartstone")
	FOnHeartstoneCrucibleForged OnHeartstoneCrucibleForged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Heartstone")
	int32 TotalForgedTraits = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Heartstone")
	bool TransmuteRemnantsToPerk(FName TraitID, int32 RequiredRemnants, float DebtReduction);
};
