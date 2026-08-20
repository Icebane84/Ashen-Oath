// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSomaticPostureControllerComponent.generated.h"

/**
 * UAshenSomaticPostureControllerComponent
 *
 * Converts StanceProfile derived from FSoulStateVector into procedural animation weight adjustments.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPostureControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureControllerComponent();

	/** Updates procedural posture animation weight from derived stance profile */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void UpdatePostureWeight(EStanceProfile Stance);

	/** Returns current posture blend weight (0.0 - 1.0) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetPostureBlendWeight() const { return PostureBlendWeight; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float PostureBlendWeight = 0.0f;
};
