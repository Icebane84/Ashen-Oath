// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenHarmonicPurificationSynergySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHarmonicPurificationExecutedSignature, float, RestoredStamina, float, EmpathicResonance);

/**
 * UAshenHarmonicPurificationSynergySubsystem
 *
 * Subsystem executing Serafina's Harmonic Purification off Kaelen's parries (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenHarmonicPurificationSynergySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|HarmonicPurification")
	void ExecuteHarmonicPurificationFromParry(float BaseRestoration = 30.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HarmonicPurification|Events")
	FOnHarmonicPurificationExecutedSignature OnHarmonicPurificationExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|HarmonicPurification")
	int32 TotalPurificationsExecuted = 0;
};
