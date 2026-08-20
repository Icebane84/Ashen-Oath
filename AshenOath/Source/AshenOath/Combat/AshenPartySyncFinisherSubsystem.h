// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPartySyncFinisherSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenPartyFinisherType : uint8
{
	None,
	// Tab 1: Canonical Base Finishers
	TripartiteResonantCleave,
	SentinelsEclipse,
	EmpathicConduitNova,
	ShepherdsIntervention,
	AshenTriangleCollapse,
	// Tab 2: Bestiary Specialized Finishers
	UmbralSymbioteMirrorShatter,
	SlagSerpentBasaltVentCauterization,
	AshenAbominationCanopyDecapitation,
	VeilHoundNegativeSpacePin,
	// Tab 3: Sub-Species, Parasites & Swarms
	GriefSwornSeveredPenance,
	SorrowLeechThermalExtraction,
	RootGnarlSubterraneanSeverance,
	AetherWeaverDimensionalCollapse,
	AshWalkerReKindledChoke,
	// Tab 4: Narrative Boss / Labyrinth Unique Finishers
	AshCasketCryoQuenchFracture,
	EchoMaimerChronosShatterAnchor,
	VowMawDesecrationSeverance,
	GuiltStitcherSeveredTetherCollapse
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyFinisherTriggered, EAshenPartyFinisherType, FinisherType, AActor*, TargetEnemy);

/**
 * UAshenPartySyncFinisherSubsystem
 * Evaluates the Finisher Selection Matrix based on enemy archetype tags,
 * posture break, companion proximity, Kaelen's Unchained state, and Serafina's Burnout meter.
 */
UCLASS()
class ASHENOATH_API UAshenPartySyncFinisherSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Finisher")
	FOnPartyFinisherTriggered OnPartyFinisherTriggered;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher")
	EAshenPartyFinisherType EvaluateFinisherEligibility(bool bKaelenDarkExpiring, float SerafinaBurnout, bool bEnemyArmored, int32 BrokenEnemiesInRadius);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher")
	EAshenPartyFinisherType EvaluateBestiaryFinisherOverride(AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher")
	bool TriggerSynchronizedFinisher(EAshenPartyFinisherType FinisherType, AActor* TargetEnemy);
};
