// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTacticalDialogueBridge.h"

UAshenTacticalDialogueBridge::UAshenTacticalDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTacticalDialogueBridge::FormatTacticalBark(
	const FName& CompanionId,
	ETacticalCommandType CommandType) const
{
	FString Bark;
	switch (CommandType)
	{
	case ETacticalCommandType::GarrettWireSnare:
		Bark = TEXT("Wire set! Pulling tension now!");
		break;
	case ETacticalCommandType::SerafinaAegisShield:
		Bark = TEXT("White Flame shields us! Hold the line!");
		break;
	case ETacticalCommandType::LyraFlankVolley:
		Bark = TEXT("Shadow volley incoming! Strike on my mark!");
		break;
	case ETacticalCommandType::CoordinatedStrike:
		Bark = TEXT("All together! Now!");
		break;
	case ETacticalCommandType::FallBackToHeal:
		Bark = TEXT("Falling back to defensive perimeter!");
		break;
	default:
		Bark = TEXT("Acknowledged!");
		break;
	}

	const FString Formatted = FString::Printf(TEXT("[%s]: %s"), *CompanionId.ToString(), *Bark);
	return FText::FromString(Formatted);
}
