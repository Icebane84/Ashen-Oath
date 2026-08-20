// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPostureAlignmentComponent.generated.h"

/**
 * UAshenSomaticPostureAlignmentComponent
 * Actor component dynamically adjusting stance posture blend weights based on current SoulState vector parameters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPostureAlignmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureAlignmentComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Posture")
	float PostureStabilityWeight = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Posture")
	void AlignSomaticPostureWithSoulState(float SoulStabilityScalar);
};
