// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenInnerDemonsSystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInnerDemonBargainOfferedSignature, FName, DemonID, float, PowerBargainMultiplier);

/**
 * UAshenInnerDemonsSystemComponent
 *
 * Component spawning active inner demon manifestations that offer tempting high-power bargains during combat.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerDemonsSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerDemonsSystemComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|InnerDemons")
	void OfferDemonBargain(FName DemonID, float Multiplier);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|InnerDemons")
	bool AcceptDemonBargain(FName DemonID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|InnerDemons|Events")
	FOnInnerDemonBargainOfferedSignature OnDemonBargainOffered;

private:
	bool bBargainAccepted = false;
};
