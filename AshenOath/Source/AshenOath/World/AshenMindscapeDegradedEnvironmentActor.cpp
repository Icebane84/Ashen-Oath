// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMindscapeDegradedEnvironmentActor.h"

AAshenMindscapeDegradedEnvironmentActor::AAshenMindscapeDegradedEnvironmentActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMindscapeDegradedEnvironmentActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeDegradedEnvironmentActor: Mindscape degraded environment actor initialized."));
}

void AAshenMindscapeDegradedEnvironmentActor::ModulateDegradedEnvironment(EAshenIntegrationDebtStage Stage)
{
	if (Stage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		WallDarknessFactor = 1.0f;
		FloorCrackDensity = 1.0f;
	}
	else if (Stage == EAshenIntegrationDebtStage::RuntimeNoise)
	{
		WallDarknessFactor = 0.75f;
		FloorCrackDensity = 0.75f;
	}
	else
	{
		WallDarknessFactor = 0.20f;
		FloorCrackDensity = 0.20f;
	}

	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeDegradedEnvironmentActor: Environment modulated for stage %d (Darkness=%f, Cracks=%f)"),
		(int32)Stage, WallDarknessFactor, FloorCrackDensity);
}
