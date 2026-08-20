// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenStaminaPulseAudioResonanceComponent.generated.h"

/**
 * UAshenStaminaPulseAudioResonanceComponent
 * Binds diegetic stamina panting audio pitch & volume to BreathingRate.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStaminaPulseAudioResonanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStaminaPulseAudioResonanceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetStaminaPantingPitch() const { return StaminaPantingPitch; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float StaminaPantingPitch = 1.0f;
};
