// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSurveySanctuaryLandmarkGASAbility.generated.h"

/**
 * UAshenSurveySanctuaryLandmarkGASAbility
 * GAS ability allowing Kaelen to survey high ground (1.5s channel), instantly revealing and inking the surrounding 2000.0uu sector on the living journal.
 */
UCLASS()
class ASHENOATH_API UAshenSurveySanctuaryLandmarkGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSurveySanctuaryLandmarkGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	float SurveyRadiusUnits = 2000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	float SurveyChannelTimeSeconds = 1.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool SurveySurroundingSector(FVector SurveyOrigin);
};
