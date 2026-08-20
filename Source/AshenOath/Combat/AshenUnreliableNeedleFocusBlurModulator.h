// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedleFocusBlurModulator.generated.h"

/**
 * UAshenUnreliableNeedleFocusBlurModulator
 * Modulates Layer III focus blur depth-of-field when Isolation >= 0.70.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleFocusBlurModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedleFocusBlurModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetFocusBlurFocalDistance() const { return FocusBlurFocalDistance; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float FocusBlurFocalDistance = 1000.0f;
};
