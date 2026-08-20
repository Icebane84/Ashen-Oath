// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCMerchantItemStockPhenotypeAdapter.h"

UAshenNPCMerchantItemStockPhenotypeAdapter::UAshenNPCMerchantItemStockPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCMerchantItemStockPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	RareStockDiscountMultiplier = 1.0f - (NewState.Resolve * 0.3f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCMerchantItemStockPhenotypeAdapter: Rare stock discount multiplier set to %.2f"), RareStockDiscountMultiplier);
}
