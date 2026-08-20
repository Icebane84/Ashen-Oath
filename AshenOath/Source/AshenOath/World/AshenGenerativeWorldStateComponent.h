// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenGenerativeWorldStateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGenerativeWorldStateUpdatedSignature, float, WeatherTension, float, MusicDissonance);

/**
 * UAshenGenerativeWorldStateComponent
 *
 * Component altering ambient weather tone, music layering, and camera tension dynamically based on Soul State Vector.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeWorldStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeWorldStateComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GenerativeWorld")
	void UpdateGenerativeWorldState(const FAshenSoulStateVector& SoulVector);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GenerativeWorld|Events")
	FOnGenerativeWorldStateUpdatedSignature OnGenerativeWorldUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GenerativeWorld")
	float CalculatedWeatherTension = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GenerativeWorld")
	float CalculatedMusicDissonance = 0.0f;
};


