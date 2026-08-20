// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctuaryVendorShopComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVendorPurchaseSignature, FName, ItemID, float, EmberCost, bool, bSuccess);

/**
 * UAshenSanctuaryVendorShopComponent
 *
 * Merchant shop component attached to sanctuary vendor NPCs. Manages catalog purchases and Ember currency validation.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryVendorShopComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryVendorShopComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vendor")
	bool PurchaseItem(AActor* BuyerActor, FName ItemID, float ItemCost);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Vendor|Events")
	FOnVendorPurchaseSignature OnVendorPurchase;
};
