// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenWayfarerJournalSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FAshenJournalEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FName EntryID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FText LocationHeader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FText KaelenLedgerText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FText GarrettMarginaliaText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	FText SerafinaMarginaliaText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	bool bGarrettHasStrikethrough = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Journal")
	float PageInkBleedIntensity = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJournalEntryAdded, const FAshenJournalEntry&, NewEntry);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJournalLayoutDistorted, bool, bIsGuardedFriction);

/**
 * UAshenWayfarerJournalSubsystem
 * World Subsystem managing journal state, entry history, active page data, and pairwise companion marginalia.
 */
UCLASS()
class ASHENOATH_API UAshenWayfarerJournalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Journal")
	FOnJournalEntryAdded OnJournalEntryAdded;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Journal")
	FOnJournalLayoutDistorted OnJournalLayoutDistorted;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Journal")
	TArray<FAshenJournalEntry> DiscoveredEntries;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	void RecordCampJournalEntry(FName EntryID, FText Location, FText KaelenText, FText GarrettNotes, FText SerafinaNotes, float GarrettTrust, float SerafinaTrust, float KaelenDebt);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	FAshenJournalEntry GetLatestJournalEntry() const;
};
