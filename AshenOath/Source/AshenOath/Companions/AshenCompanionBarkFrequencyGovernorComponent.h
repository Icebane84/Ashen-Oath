// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionBarkFrequencyGovernorComponent.generated.h"

/**
 * UAshenCompanionBarkFrequencyGovernorComponent
 * Governs dialogue bark frequency to prevent repetition during long boss fights.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBarkFrequencyGovernorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBarkFrequencyGovernorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	bool CanPlayBarkCategory(FName BarkCategory, float CurrentGameTime);

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	TMap<FName, float> LastBarkPlayTimes;
};
