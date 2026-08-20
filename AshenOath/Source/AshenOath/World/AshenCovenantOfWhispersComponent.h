// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCovenantOfWhispersComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCovenantPactBoundSignature, FName, PactID, float, PowerBoonMultiplier);

/**
 * UAshenCovenantOfWhispersComponent
 *
 * Component allowing Kaelen to form temporary pacts with different facets of Eldrin's consciousness.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCovenantOfWhispersComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCovenantOfWhispersComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|CovenantOfWhispers")
	bool FormCovenantPact(FName PactID, float BoonMultiplier);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CovenantOfWhispers")
	void BreakCovenantPact(FName PactID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CovenantOfWhispers|Events")
	FOnCovenantPactBoundSignature OnCovenantPactBound;

private:
	TSet<FName> ActiveCovenants;
};
