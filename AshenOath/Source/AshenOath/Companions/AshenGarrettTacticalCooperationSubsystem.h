// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenGarrettTacticalCooperationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTacticalCooperationUpdatedSignature, float, ActiveCooperationLevel, float, FlankSynergyBonusMultiplier);

/**
 * UAshenGarrettTacticalCooperationSubsystem
 *
 * Subsystem tracking Garrett's tactical cooperation level with Kaelen (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettTacticalCooperationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettCooperation")
	void ModifyTacticalCooperation(float DeltaCooperation);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettCooperation|Events")
	FOnTacticalCooperationUpdatedSignature OnCooperationUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettCooperation")
	float ActiveCooperationLevel = 75.0f;
};
