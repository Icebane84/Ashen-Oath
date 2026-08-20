// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenLivingJournalSubsystem.generated.h"

/**
 * UAshenLivingJournalSubsystem
 * GameInstance Subsystem managing persistent multi-author journal entries, somatic resolution beats, and unlocked tactical frame perks.
 */
UCLASS()
class ASHENOATH_API UAshenLivingJournalSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	TMap<FName, FJournalResolutionEntry> JournalEntries;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	TMap<FName, FTacticalFramePerkData> UnlockedFramePerks;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	void RecordSomaticResolutionBeat(FName MonsterID, EJournalPerspectiveType Perspective);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	bool HasTacticalFramePerk(FName MonsterArchetype) const;
};
