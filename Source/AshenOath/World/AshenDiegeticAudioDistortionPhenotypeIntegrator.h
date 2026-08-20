// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticAudioDistortionPhenotypeIntegrator.generated.h"

/**
 * UAshenDiegeticAudioDistortionPhenotypeIntegrator
 * Connects diegetic audio distortion subsystem to FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticAudioDistortionPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticAudioDistortionPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetAudioDistortion() const { return AudioDistortion; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float AudioDistortion = 0.0f;
};
