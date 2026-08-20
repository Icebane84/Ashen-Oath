// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCMerchantPriceScaleAdapterComponent.h"

UAshenNPCMerchantPriceScaleAdapterComponent::UAshenNPCMerchantPriceScaleAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCMerchantPriceScaleAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	MerchantPriceMarkupMultiplier = 1.0f + (NewState.Corruption * 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCMerchantPriceScaleAdapterComponent: Merchant price markup multiplier set to %.2f"), MerchantPriceMarkupMultiplier);
}
