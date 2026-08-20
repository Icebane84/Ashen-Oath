// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSanctuaryVendorEconomySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVendorPriceAdjustedSignature, FName, ItemID, float, AdjustedPrice);

/**
 * UAshenSanctuaryVendorEconomySubsystem
 *
 * Subsystem driving sanctuary item prices and trade stock.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryVendorEconomySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VendorEconomy")
	float EvaluateItemPrice(FName ItemID, float BasePrice, float ReputationDiscountPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VendorEconomy|Events")
	FOnVendorPriceAdjustedSignature OnVendorPriceAdjusted;
};
