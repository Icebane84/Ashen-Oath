// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenUnchainedBerserkModeController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnchainedBerserkStateUpdatedSignature, float, SpeedMultiplier, bool, bHitStopRemoved);

/**
 * UAshenUnchainedBerserkModeController
 *
 * Controller removing hit-stop and boosting attack speed by 200% under Stance.UnchainedBerserk.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenUnchainedBerserkModeController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UnchainedBerserk")
	void EngageUnchainedBerserkMode();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UnchainedBerserk|Events")
	FOnUnchainedBerserkStateUpdatedSignature OnBerserkUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedBerserk")
	bool bIsUnchainedActive = false;
};
