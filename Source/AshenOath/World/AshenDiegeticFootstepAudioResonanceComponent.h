// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticFootstepAudioResonanceComponent.generated.h"

/**
 * UAshenDiegeticFootstepAudioResonanceComponent
 * Binds footstep audio weight and surface resonance to StanceProfile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticFootstepAudioResonanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticFootstepAudioResonanceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetFootstepWeightScalar() const { return FootstepWeightScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float FootstepWeightScalar = 1.0f;
};
