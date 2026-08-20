// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherCompanionReactionAdapter.generated.h"

/**
 * UAshenWeatherCompanionReactionAdapter
 * Coordinates companion equipment toggles (weather hoods, respirators) and shelter-seeking behaviors during extreme atmospheric shifts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	FName EvaluateCompanionWeatherGear(FName CompanionID, EWeatherState Weather, float Toxicity);
};
