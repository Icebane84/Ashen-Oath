// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeAmbientAudioDissonanceAdapter.generated.h"

/**
 * UAshenGenerativeAmbientAudioDissonanceAdapter
 * Modulates ambient wind/foliage audio pitch based on IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeAmbientAudioDissonanceAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeAmbientAudioDissonanceAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetAmbientAudioPitchMultiplier() const { return AmbientAudioPitchMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float AmbientAudioPitchMultiplier = 1.0f;
};
