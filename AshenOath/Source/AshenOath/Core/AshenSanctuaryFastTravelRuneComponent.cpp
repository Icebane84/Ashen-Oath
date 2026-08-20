// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 296: Ashen Sanctuary Fast Travel Rune Component

#include "AshenSanctuaryFastTravelRuneComponent.h"

UAshenSanctuaryFastTravelRuneComponent::UAshenSanctuaryFastTravelRuneComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	RuneID = FName("SanctuaryRune_TarnSpire");
	bIsActivated = false;
}

void UAshenSanctuaryFastTravelRuneComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSanctuaryFastTravelRuneComponent::ActivateRune()
{
	if (bIsActivated) return true;

	bIsActivated = true;
	OnRuneActivated.Broadcast(RuneID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryFastTravelRuneComponent: SANCTUARY FAST TRAVEL RUNE '%s' ACTIVATED."),
		*RuneID.ToString());

	return true;
}
