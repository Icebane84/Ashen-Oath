// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenWhisperingVoidErosionVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVoidErosionAppliedSignature, AActor*, TargetActor, float, StainErosionRatePerSec);

/**
 * AAshenWhisperingVoidErosionVolume
 *
 * World Volume applying spiritual stain erosion & audio distortion to players inside Void zones (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API AAshenWhisperingVoidErosionVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenWhisperingVoidErosionVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VoidErosion")
	void ApplyVoidErosionToActor(AActor* TargetActor, float ErosionRate = 5.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VoidErosion|Events")
	FOnVoidErosionAppliedSignature OnVoidErosionApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidErosion")
	float ActiveErosionRate = 5.0f;
};
