// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCMerchantItemStockPhenotypeAdapter.generated.h"

/**
 * UAshenNPCMerchantItemStockPhenotypeAdapter
 * Shifts rare merchant items in stock based on Kaelen's Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCMerchantItemStockPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCMerchantItemStockPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetRareStockDiscountMultiplier() const { return RareStockDiscountMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float RareStockDiscountMultiplier = 1.0f;
};
