// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenTemporalDilationDesaturationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTemporalDilationAppliedSignature, float, ActiveTimeDilation, float, DesaturationIntensity);

/**
 * UAshenTemporalDilationDesaturationSubsystem
 *
 * Subsystem dilating time to 10% speed and draining world color to slate-grey silhouettes (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenTemporalDilationDesaturationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TemporalDilation")
	void ApplyTemporalDilation(float DilationScale = 0.10f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TemporalDilation|Events")
	FOnTemporalDilationAppliedSignature OnTemporalDilationApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|TemporalDilation")
	float ActiveTimeDilation = 1.0f;
};
