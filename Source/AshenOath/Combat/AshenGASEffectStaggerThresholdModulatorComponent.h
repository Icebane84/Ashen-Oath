// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASEffectStaggerThresholdModulatorComponent.generated.h"

/**
 * UAshenGASEffectStaggerThresholdModulatorComponent
 * Modulates stagger poise thresholds based on Dissonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASEffectStaggerThresholdModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASEffectStaggerThresholdModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStaggerPoiseMultiplier() const { return StaggerPoiseMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float StaggerPoiseMultiplier = 1.0f;
};
