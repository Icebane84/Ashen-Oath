// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMechanicalHonestyRuleEnforcer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMechanicalHonestyAuditedSignature, FName, SystemName, bool, bIsAuthentic);

/**
 * UAshenMechanicalHonestyRuleEnforcer
 *
 * Subsystem guaranteeing hitboxes, frame data, and stamina costs are NEVER falsified by psychological passes.
 */
UCLASS()
class ASHENOATH_API UAshenMechanicalHonestyRuleEnforcer : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MechanicalHonesty")
	bool ValidateMechanicalTruth(FName SystemName, float RawValue, float PresentedValue);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MechanicalHonesty|Events")
	FOnMechanicalHonestyAuditedSignature OnMechanicalHonestyAudited;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MechanicalHonesty")
	int32 TotalAuditPasses = 0;
};
