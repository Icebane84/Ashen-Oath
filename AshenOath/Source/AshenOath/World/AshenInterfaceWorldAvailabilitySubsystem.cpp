// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 607: Ashen Interface World Availability Subsystem

#include "AshenInterfaceWorldAvailabilitySubsystem.h"

void UAshenInterfaceWorldAvailabilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenInterfaceWorldAvailabilitySubsystem: Initialized — UI World Availability Subsystem ONLINE."));
}

bool UAshenInterfaceWorldAvailabilitySubsystem::CanOpenUIScreen(EAshenDiegeticUIScreen Screen, bool bNearActiveCampfire, bool bNearHeartstoneShrine)
{
	bool bAllowed = false;

	switch (Screen)
	{
	case EAshenDiegeticUIScreen::FieldJournal:
	case EAshenDiegeticUIScreen::Equipment:
		bAllowed = true;
		break;
	case EAshenDiegeticUIScreen::Camp:
		bAllowed = bNearActiveCampfire;
		break;
	case EAshenDiegeticUIScreen::MemoryPalace:
		bAllowed = bNearActiveCampfire || bNearHeartstoneShrine;
		break;
	case EAshenDiegeticUIScreen::HeartstoneSanctuary:
		bAllowed = bNearHeartstoneShrine;
		break;
	case EAshenDiegeticUIScreen::JourneyArchive:
		bAllowed = true;
		break;
	default:
		bAllowed = false;
		break;
	}

	OnAvailabilityEvaluated.Broadcast(Screen, bAllowed);

	UE_LOG(LogTemp, Log, TEXT("UAshenInterfaceWorldAvailabilitySubsystem: UI AVAILABILITY EVALUATED -> Screen %d | Allowed: %s."),
		static_cast<int32>(Screen), bAllowed ? TEXT("TRUE") : TEXT("FALSE"));

	return bAllowed;
}
