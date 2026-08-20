// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_JourneyArchive.generated.h"

/**
 * UAshenUserWidget_JourneyArchive
 *
 * UMG backing widget for Journey Archive ("Which journey is this?").
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_JourneyArchive : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayJourneyArchiveRecord(FName JourneySaveID, FString TimelineSummary, int32 TotalExpeditions);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveJourneySaveID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FString ActiveTimelineSummaryText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 ActiveTotalExpeditions = 0;
};
