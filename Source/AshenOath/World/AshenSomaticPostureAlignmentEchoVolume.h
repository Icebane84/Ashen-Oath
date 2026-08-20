// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenSomaticPostureAlignmentEchoVolume.generated.h"

/**
 * AAshenSomaticPostureAlignmentEchoVolume
 * Spatial volume component emitting posture stance alignment echo fields and psychological balance scalars.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticPostureAlignmentEchoVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenSomaticPostureAlignmentEchoVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float PostureAlignmentEchoIntensity = 0.80f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ApplyPostureAlignmentEchoToActor(AActor* TargetActor);
};
