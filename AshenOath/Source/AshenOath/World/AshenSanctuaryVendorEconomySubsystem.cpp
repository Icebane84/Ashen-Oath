// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 578: Ashen Sanctuary Vendor Economy Subsystem

#include "AshenSanctuaryVendorEconomySubsystem.h"

void UAshenSanctuaryVendorEconomySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryVendorEconomySubsystem: Initialized — Sanctuary Vendor Economy Engine ONLINE."));
}

float UAshenSanctuaryVendorEconomySubsystem::EvaluateItemPrice(FName ItemID, float BasePrice, float ReputationDiscountPercent)
{
	const float DiscountMult = FMath::Clamp(1.0f - (ReputationDiscountPercent / 100.0f), 0.5f, 1.0f);
	const float FinalPrice = BasePrice * DiscountMult;

	OnVendorPriceAdjusted.Broadcast(ItemID, FinalPrice);

	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryVendorEconomySubsystem: VENDOR PRICE EVALUATED -> Item '%s' (Base: %.0f | Final: %.0f)."),
		*ItemID.ToString(), BasePrice, FinalPrice);

	return FinalPrice;
}
