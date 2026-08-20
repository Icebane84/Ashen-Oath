// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenParryWindowPerceptionDistortionComponent.generated.h"

/**
 * UAshenParryWindowPerceptionDistortionComponent
 * Modulates Layer III visual & haptic parry cues without affecting Layer I hit detection.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParryWindowPerceptionDistortionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParryWindowPerceptionDistortionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetParryVisualOffset() const { return ParryVisualOffset; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float ParryVisualOffset = 0.0f;
};
