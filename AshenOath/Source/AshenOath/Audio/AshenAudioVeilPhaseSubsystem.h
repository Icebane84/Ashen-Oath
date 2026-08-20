// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPrismaticRealmVeilSubsystem.h"
#include "AshenAudioVeilPhaseSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAudioVeilPhaseShiftedSignature, EAshenWorldVeilState, VeilState, float, LowPassCutoffFreq);

/**
 * UAshenAudioVeilPhaseSubsystem
 *
 * World Subsystem shifting ambient audio stems and applying low-pass filters during Prismatic Void phase shifts.
 */
UCLASS()
class ASHENOATH_API UAshenAudioVeilPhaseSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioVeil")
	void ShiftAudioVeilState(EAshenWorldVeilState VeilState);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioVeil|Events")
	FOnAudioVeilPhaseShiftedSignature OnAudioVeilShifted;
};
