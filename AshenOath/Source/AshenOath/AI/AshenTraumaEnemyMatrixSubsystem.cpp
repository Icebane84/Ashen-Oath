// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenTraumaEnemyMatrixSubsystem.h"

void UAshenTraumaEnemyMatrixSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegisteredAdversarialArguments.Empty();

	// Pre-register canonical Ashen Abomination argument
	RegisterAdversarialArgument(
		FName(TEXT("Monster.AshenAbomination")),
		FName(TEXT("Hero.Kaelen")),
		TEXT("My value is measured by how much pain I can absorb alone."),
		TEXT("Sacrifice is Selfish: Your solitary martyrdom only causes more agony to your allies."),
		ETEMEncounterTier::Revelation
	);

	UE_LOG(LogTemp, Log, TEXT("UAshenTraumaEnemyMatrixSubsystem: Trauma Enemy Matrix Subsystem initialized."));
}
void UAshenTraumaEnemyMatrixSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenTraumaEnemyMatrixSubsystem::RegisterAdversarialArgument(FName MonsterID, FName TargetHero, const FString& CoreLie, const FString& Thesis, ETEMEncounterTier Tier)
{
	FAdversarialArgument Arg;
	Arg.MonsterID = MonsterID;
	Arg.TargetedHero = TargetHero;
	Arg.CoreLieTargeted = CoreLie;
	Arg.PhilosophicalThesis = Thesis;
	Arg.Tier = Tier;

	RegisteredAdversarialArguments.Add(MonsterID, Arg);
	UE_LOG(LogTemp, Warning, TEXT("UAshenTraumaEnemyMatrixSubsystem: Registered Adversarial Argument for %s against %s (Tier: %d)."),
		*MonsterID.ToString(), *TargetHero.ToString(), static_cast<int32>(Tier));
}

bool UAshenTraumaEnemyMatrixSubsystem::GetAdversarialArgument(FName MonsterID, FAdversarialArgument& OutArgument) const
{
	const FAdversarialArgument* Found = RegisteredAdversarialArguments.Find(MonsterID);
	if (Found)
	{
		OutArgument = *Found;
		return true;
	}
	return false;
}
