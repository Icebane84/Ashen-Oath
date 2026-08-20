// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicGroundingSubsystem.generated.h"

/**
 * UAshenEpistemicGroundingSubsystem
 * GameInstance Subsystem managing Layer 0 canonical combat ground truth and coordinating the 5-layer epistemic consequence stack.
 */
UCLASS()
class ASHENOATH_API UAshenEpistemicGroundingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Epistemic")
	TArray<FCanonicalCombatEvent> CanonicalEventLog;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Epistemic")
	FGuid RecordCanonicalCombatEvent(FName EncounterID, FName FinisherUsed, EConsequenceProfileTier Tier, bool bIsSynarchy, float Trust);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Epistemic")
	int32 GetMilestoneEventsCount() const;
};
