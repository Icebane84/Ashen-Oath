// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedlePhenotypeIntegrator.generated.h"

/**
 * UAshenUnreliableNeedlePhenotypeIntegrator
 * Connects unreliable needle matrix component to Layer III perception distortion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedlePhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedlePhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetPerceptionNoise() const { return PerceptionNoise; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float PerceptionNoise = 0.0f;
};
