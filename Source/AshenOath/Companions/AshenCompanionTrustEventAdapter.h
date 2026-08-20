// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustEventAdapter.generated.h"

/**
 * UAshenCompanionTrustEventAdapter
 * Dispatches granular trust delta events (protective action +0.05, abandonment -0.08, oath fulfillment +0.03) into the ImprintBuffer.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustEventAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionTrustEventAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void NotifyProtectiveAction(FName CompanionID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void NotifyTacticalAbandonment(FName CompanionID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void NotifyOathFulfilled();
};
