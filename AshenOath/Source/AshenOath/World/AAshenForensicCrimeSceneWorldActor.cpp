// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenForensicCrimeSceneWorldActor.h"
#include "Narrative/AshenForensicMindscapeConvergenceSubsystem.h"
#include "Engine/World.h"

AAshenForensicCrimeSceneWorldActor::AAshenForensicCrimeSceneWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	SceneClueId = TEXT("Clue_Autopsy_CorruptedKnight_01");
	ClueCategory = EForensicClueCategory::PhysicalAutopsyEvidence;
	ClueTitle = FText::FromString(TEXT("Severed Corrupted Sternum"));
	ClueDescription = FText::FromString(TEXT("Deep inverted slash angle indicates an upward thrust executed from a crouched plow guard."));
	bIsInspected = false;
}

void AAshenForensicCrimeSceneWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenForensicCrimeSceneWorldActor::InspectScene()
{
	if (!bIsInspected)
	{
		bIsInspected = true;

		if (UWorld* World = GetWorld())
		{
			if (UAshenForensicMindscapeConvergenceSubsystem* Subsystem = World->GetSubsystem<UAshenForensicMindscapeConvergenceSubsystem>())
			{
				FForensicClueRecord Clue;
				Clue.ClueId = SceneClueId;
				Clue.Category = ClueCategory;
				Clue.ClueTitle = ClueTitle;
				Clue.ClueDescription = ClueDescription;
				Clue.ReliabilityWeight = 1.0f;

				Subsystem->DiscoverClue(Clue);
			}
		}
	}
}
