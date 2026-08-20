// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMindscapeTransitionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMindscapeStateTransitionedSignature, FName, MindscapeID, float, DistortionIntensity);

/**
 * UAshenMindscapeTransitionSubsystem
 *
 * World Subsystem modulating hallucinatory zones and projecting into 3 layers:
 * Layer 1 (Combat): Altered gravity & stamina decay in mindscape zones.
 * Layer 2 (VFX/PostProcess): Post-process color inversion & MetaSound audio modulation.
 * Layer 3 (Narrative): Unlocks hidden memory thread dialogues.
 */
UCLASS()
class ASHENOATH_API UAshenMindscapeTransitionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mindscape")
	void TransitionMindscapeState(FName MindscapeID, float DistortionIntensity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Mindscape")
	float GetActiveDistortionIntensity() const { return CurrentDistortionIntensity; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mindscape|Events")
	FOnMindscapeStateTransitionedSignature OnMindscapeTransitioned;

private:
	float CurrentDistortionIntensity = 0.0f;
};
