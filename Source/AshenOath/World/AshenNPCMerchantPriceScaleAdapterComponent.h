// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCMerchantPriceScaleAdapterComponent.generated.h"

/**
 * UAshenNPCMerchantPriceScaleAdapterComponent
 * Modulates merchant item prices based on Kaelen's Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCMerchantPriceScaleAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCMerchantPriceScaleAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetMerchantPriceMarkupMultiplier() const { return MerchantPriceMarkupMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float MerchantPriceMarkupMultiplier = 1.0f;
};
