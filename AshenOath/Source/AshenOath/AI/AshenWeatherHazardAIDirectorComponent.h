// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherHazardAIDirectorComponent.generated.h"

/**
 * UAshenWeatherHazardAIDirectorComponent
 * AI Director modulating enemy aggression multipliers and storm frenzy states based on active weather patterns.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherHazardAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherHazardAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	float CalculateEnemyAggressionMultiplier(EWeatherState Weather) const;
};
