// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioDualHarmonicSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDualHarmonicAudioShiftSignature, bool, bIsHarmonicActive, float, HarmonicBlendWeight);

/**
 * UAshenAudioDualHarmonicSubsystem
 *
 * World Subsystem stripping ragged breathing audio stems and blending cold dual-harmonic voice authority during Unchained Vessel state (UMB-SYS-005).
 */
UCLASS()
class ASHENOATH_API UAshenAudioDualHarmonicSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioHarmonic")
	void ShiftToDualHarmonicAuthority(bool bEnableHarmonic, float BlendWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioHarmonic|Events")
	FOnDualHarmonicAudioShiftSignature OnDualHarmonicAudioShift;

private:
	bool bHarmonicActive = false;
};
