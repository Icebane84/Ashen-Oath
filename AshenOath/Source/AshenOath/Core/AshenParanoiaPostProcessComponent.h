// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParanoiaPostProcessComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParanoiaVFXUpdatedSignature, float, VignetteIntensity, float, ChromaticAberrationJitter);

/**
 * UAshenParanoiaPostProcessComponent
 *
 * Drives post-process vignette contraction and chromatic aberration channel jitter
 * based on the player's ParanoiaLevel (0.0 to 100.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParanoiaPostProcessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParanoiaPostProcessComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ParanoiaVFX")
	void UpdateParanoiaVFX(float ParanoiaLevel);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ParanoiaVFX")
	float GetVignetteIntensity() const { return CurrentVignette; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|ParanoiaVFX")
	float GetChromaticAberration() const { return CurrentChromaticAberration; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ParanoiaVFX|Events")
	FOnParanoiaVFXUpdatedSignature OnParanoiaVFXUpdated;

private:
	float CurrentVignette = 0.0f;
	float CurrentChromaticAberration = 0.0f;
};
