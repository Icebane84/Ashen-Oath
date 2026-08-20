// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenWeatherDialogueAdapter.h"

UAshenWeatherDialogueAdapter::UAshenWeatherDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeatherDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWeatherDialogueAdapter::TriggerWeatherWarningBark(FName CompanionID, EWeatherState Weather, float FilterHealth)
{
	FString Bark = TEXT("The wind is picking up.");
	if (FilterHealth <= 0.20f)
	{
		Bark = TEXT("My respirator is choking on ash! We need to find shelter!");
	}
	else if (Weather == EWeatherState::VoidMiasma)
	{
		Bark = TEXT("Void miasma ahead. Seal your masks, tight!");
	}
	else if (Weather == EWeatherState::PsychicStorm)
	{
		Bark = TEXT("Psychic storm lightning inbound—keep moving!");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeatherDialogueAdapter: %s: \"%s\" (Weather: %d, Filter: %.1f%%)"),
		*CompanionID.ToString(), *Bark, static_cast<int32>(Weather), FilterHealth * 100.0f);
}
