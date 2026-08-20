// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenSanctuaryConstellationChamberLightActor.generated.h"

/**
 * AAshenSanctuaryConstellationChamberLightActor
 * Sanctuary chamber ambient light actor responding to constellation node count & state vector.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryConstellationChamberLightActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryConstellationChamberLightActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetAmbientLightIntensity() const { return AmbientLightIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float AmbientLightIntensity = 5000.0f;
};
