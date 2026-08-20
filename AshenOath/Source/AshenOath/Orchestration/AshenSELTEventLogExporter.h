// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSELTEventLogExporter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSELTEventLoggedSignature, FName, EventTag, FString, EventSummaryText);

/**
 * UAshenSELTEventLogExporter
 *
 * Session Event & Lore Tracker exporter logging runtime C++ events into graph SELT history.
 */
UCLASS()
class ASHENOATH_API UAshenSELTEventLogExporter : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SELTExporter")
	void LogSELTEvent(FName EventTag, FString SummaryText);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SELTExporter|Events")
	FOnSELTEventLoggedSignature OnSELTLogged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SELTExporter")
	int32 TotalSELTEventsLogged = 0;
};
