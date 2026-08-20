// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenInterfaceWorldAvailabilitySubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenDiegeticUIScreen : uint8
{
	FieldJournal         UMETA(DisplayName = "Field Journal (Anywhere)"),
	Equipment            UMETA(DisplayName = "Equipment Inspection (Anywhere)"),
	Camp                 UMETA(DisplayName = "Camp Behavior (Active Campfires Only)"),
	MemoryPalace         UMETA(DisplayName = "Memory Palace (Camp or Heartstones)"),
	HeartstoneSanctuary  UMETA(DisplayName = "Heartstone Sanctuary (Heartstones Only)"),
	JourneyArchive       UMETA(DisplayName = "Journey Archive (Main Menu or Sanctuary)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUIScreenAvailabilityEvaluatedSignature, EAshenDiegeticUIScreen, TargetScreen, bool, bIsAvailable);

/**
 * UAshenInterfaceWorldAvailabilitySubsystem
 *
 * World Subsystem enforcing world rules for UI availability.
 */
UCLASS()
class ASHENOATH_API UAshenInterfaceWorldAvailabilitySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UIRules")
	bool CanOpenUIScreen(EAshenDiegeticUIScreen Screen, bool bNearActiveCampfire, bool bNearHeartstoneShrine);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UIRules|Events")
	FOnUIScreenAvailabilityEvaluatedSignature OnAvailabilityEvaluated;
};
