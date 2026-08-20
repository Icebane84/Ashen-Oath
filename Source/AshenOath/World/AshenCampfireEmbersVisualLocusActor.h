// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireEmbersVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireEmbersUpdatedSignature, float, EmberIntensity, float, WarmthRadius);

/**
 * AAshenCampfireEmbersVisualLocusActor
 *
 * World Actor rendering glowing campfire ember particle FX and warm point lights (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenCampfireEmbersVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireEmbersVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CampfireEmbers")
	void UpdateCampfireEmberIntensity(float Intensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CampfireEmbers|Events")
	FOnCampfireEmbersUpdatedSignature OnEmbersUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CampfireEmbers")
	float ActiveEmberIntensity = 1.0f;
};
