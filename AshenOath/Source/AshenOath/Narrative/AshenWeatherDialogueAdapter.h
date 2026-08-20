// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherDialogueAdapter.generated.h"

/**
 * UAshenWeatherDialogueAdapter
 * Triggers companion tactical voice barks and weather warnings upon sudden atmospheric shifts or filter depletion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerWeatherWarningBark(FName CompanionID, EWeatherState Weather, float FilterHealth);
};
