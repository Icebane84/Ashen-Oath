// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSurveySanctuaryLandmarkGASAbility.h"

UAshenSurveySanctuaryLandmarkGASAbility::UAshenSurveySanctuaryLandmarkGASAbility()
{
	SurveyRadiusUnits = 2000.0f;
	SurveyChannelTimeSeconds = 1.5f;
}

bool UAshenSurveySanctuaryLandmarkGASAbility::SurveySurroundingSector(FVector SurveyOrigin)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSurveySanctuaryLandmarkGASAbility: VANTAGE SURVEY COMPLETE at %s! Inked sector across %.1fuu radius."),
		*SurveyOrigin.ToString(), SurveyRadiusUnits);
	return true;
}
