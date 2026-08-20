// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "AshenUnchainedCameraModifier.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnchainedCameraShiftedSignature, float, TargetFOV, float, ShakeIntensity);

/**
 * UAshenUnchainedCameraModifier
 *
 * Camera modifier providing dynamic FOV shifts and trauma camera shake during Unchained Berserk.
 */
UCLASS()
class ASHENOATH_API UAshenUnchainedCameraModifier : public UCameraModifier
{
	GENERATED_BODY()

public:
	UAshenUnchainedCameraModifier();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UnchainedCamera")
	void TriggerUnchainedFOVShift(float TargetFOV, float Intensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UnchainedCamera|Events")
	FOnUnchainedCameraShiftedSignature OnCameraShifted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UnchainedCamera")
	float ActiveFOVOffset = 0.0f;
};
