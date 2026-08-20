// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenSanctuaryConstellationOrbitorActor.generated.h"

/**
 * AAshenSanctuaryConstellationOrbitorActor
 * World actor driving orbiting soul energy spheres in Sanctuary.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryConstellationOrbitorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryConstellationOrbitorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetOrbiterVelocityMultiplier() const { return OrbiterVelocityMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float OrbiterVelocityMultiplier = 1.0f;
};
