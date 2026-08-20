// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPartySyncFinisherSubsystem.h"

void UAshenPartySyncFinisherSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenPartySyncFinisherSubsystem: Party Synchronized Finisher Subsystem initialized (18 archetypes active)."));
}

EAshenPartyFinisherType UAshenPartySyncFinisherSubsystem::EvaluateBestiaryFinisherOverride(AActor* TargetActor)
{
	if (!TargetActor)
	{
		return EAshenPartyFinisherType::None;
	}

	// Tab 4: Boss / Labyrinth Unique Finishers
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Boss.AshCasket")))) return EAshenPartyFinisherType::AshCasketCryoQuenchFracture;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Boss.EchoMaimer")))) return EAshenPartyFinisherType::EchoMaimerChronosShatterAnchor;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Boss.VowMaw")))) return EAshenPartyFinisherType::VowMawDesecrationSeverance;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Boss.GuiltStitcher")))) return EAshenPartyFinisherType::GuiltStitcherSeveredTetherCollapse;

	// Tab 2: Bestiary Specialized Finishers
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.UmbralSymbiote")))) return EAshenPartyFinisherType::UmbralSymbioteMirrorShatter;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.SlagSerpent")))) return EAshenPartyFinisherType::SlagSerpentBasaltVentCauterization;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.AshenAbomination")))) return EAshenPartyFinisherType::AshenAbominationCanopyDecapitation;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.VeilHound")))) return EAshenPartyFinisherType::VeilHoundNegativeSpacePin;

	// Tab 3: Sub-Species, Parasites & Swarms
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.GriefSworn")))) return EAshenPartyFinisherType::GriefSwornSeveredPenance;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.SorrowLeech")))) return EAshenPartyFinisherType::SorrowLeechThermalExtraction;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.RootGnarl")))) return EAshenPartyFinisherType::RootGnarlSubterraneanSeverance;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.AetherWeaver")))) return EAshenPartyFinisherType::AetherWeaverDimensionalCollapse;
	if (TargetActor->ActorHasTag(FName(TEXT("Enemy.Bestiary.AshWalkerSwarm")))) return EAshenPartyFinisherType::AshWalkerReKindledChoke;

	return EAshenPartyFinisherType::None;
}

EAshenPartyFinisherType UAshenPartySyncFinisherSubsystem::EvaluateFinisherEligibility(
	bool bKaelenDarkExpiring, float SerafinaBurnout, bool bEnemyArmored, int32 BrokenEnemiesInRadius)
{
	// Priority 1: Crisis Control
	if (bKaelenDarkExpiring)
	{
		return EAshenPartyFinisherType::ShepherdsIntervention;
	}

	// Priority 2: Empathic Inversion (Serafina Vulnerable)
	if (SerafinaBurnout >= 0.70f)
	{
		return EAshenPartyFinisherType::EmpathicConduitNova;
	}

	// Priority 3: Spatial AoE Geometry (3+ broken targets)
	if (BrokenEnemiesInRadius >= 3)
	{
		return EAshenPartyFinisherType::AshenTriangleCollapse;
	}

	// Priority 4: Armor Shredding Opportunism
	if (bEnemyArmored)
	{
		return EAshenPartyFinisherType::SentinelsEclipse;
	}

	// Default: Tripartite Resonant Cleave
	return EAshenPartyFinisherType::TripartiteResonantCleave;
}

bool UAshenPartySyncFinisherSubsystem::TriggerSynchronizedFinisher(EAshenPartyFinisherType FinisherType, AActor* TargetEnemy)
{
	if (FinisherType == EAshenPartyFinisherType::None)
	{
		return false;
	}

	if (OnPartyFinisherTriggered.IsBound())
	{
		OnPartyFinisherTriggered.Broadcast(FinisherType, TargetEnemy);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenPartySyncFinisherSubsystem: Triggered Synchronized Finisher [Type %d] on target %s!"),
		(int32)FinisherType, TargetEnemy ? *TargetEnemy->GetName() : TEXT("Target"));
	return true;
}
