// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuaryBeaconJournalRegistrarComponent.generated.h"

/**
 * UAshenSanctuaryBeaconJournalRegistrarComponent
 * 
 * Auto-registers discovered ancient beacons, regional weather patterns, and botanical sketches into Kaelen's diegetic Forensic Journal.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryBeaconJournalRegistrarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryBeaconJournalRegistrarComponent();

	/** Formats journal entry for beacon discovery */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Journal")
	FText FormatBeaconJournalEntry(FName BeaconId, const FString& RegionName) const;

	/** Gets total recorded entries count */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Journal")
	int32 GetRecordedJournalCount() const { return InscribedJournalEntries.Num(); }

	UFUNCTION(BlueprintCallable, Category = "Ashen|Survival|Journal")
	void RecordEntry(const FText& Entry);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Survival|Journal")
	TArray<FText> InscribedJournalEntries;
};
