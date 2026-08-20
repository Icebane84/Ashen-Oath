// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenWillpowerRewardMatrixSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWillpowerUnbrokenTriggeredSignature, float, StaminaRecoveryBoostPercent, int32, ExtraParryFrames, bool, bSmiteRiposteUnlocked);

/**
 * UAshenWillpowerRewardMatrixSubsystem
 *
 * Subsystem validating restraint, applying State.Willpower.Unbroken (The Willpower Reward Matrix, PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenWillpowerRewardMatrixSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WillpowerMatrix")
	void TriggerUnbrokenState();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WillpowerMatrix|Events")
	FOnWillpowerUnbrokenTriggeredSignature OnUnbrokenTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WillpowerMatrix")
	bool bIsStateUnbrokenActive = false;
};
