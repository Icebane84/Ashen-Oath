// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenWordlessSupportEvaluatorComponent.h"

UAshenWordlessSupportEvaluatorComponent::UAshenWordlessSupportEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FWordlessSupportCommand UAshenWordlessSupportEvaluatorComponent::EvaluateSupportAction(
	FName CompanionName,
	float CompanionTrust,
	const FVector& KaelenLocation,
	const FVector& NearestObstacleLocation) const
{
	FWordlessSupportCommand Command;
	Command.CompanionName = CompanionName;
	Command.TargetWorldLocation = NearestObstacleLocation;
	Command.bSuppressDialoguePrompt = true;

	const float DistanceToObstacle = FVector::Dist(KaelenLocation, NearestObstacleLocation);

	// If obstacle is within 800uu and trust is high, Garrett clears it ahead of Kaelen
	if (DistanceToObstacle <= 800.0f && CompanionTrust >= 0.65f)
	{
		Command.ActionType = EWordlessSupportActionType::ClearCivilianObstacle;
		return Command;
	}

	if (CompanionTrust >= 0.50f)
	{
		Command.ActionType = EWordlessSupportActionType::MatchLocomotionPace;
		return Command;
	}

	Command.ActionType = EWordlessSupportActionType::None;
	return Command;
}
