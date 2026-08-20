// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSerafinaHarmonicAuraSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHarmonicAuraUpdatedSignature, float, ActiveAuraRadius, float, PassivePurificationPower);

/**
 * UAshenSerafinaHarmonicAuraSubsystem
 *
 * Subsystem managing Serafina's passive aura range and purification power (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaHarmonicAuraSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAura")
	void ExpandHarmonicAura(float RadiusDelta = 100.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAura|Events")
	FOnHarmonicAuraUpdatedSignature OnAuraUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaAura")
	float ActiveAuraRadius = 800.0f;
};
