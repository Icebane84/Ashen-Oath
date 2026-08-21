// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_SquadCommandWheelHUD.h"

UAshenUserWidget_SquadCommandWheelHUD::UAshenUserWidget_SquadCommandWheelHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SelectedSectorIndex = 0;
	SelectedCommand = ETacticalCommandType::None;
}

void UAshenUserWidget_SquadCommandWheelHUD::UpdateSelectedSector(float StickAngleDegrees)
{
	// Normalize angle to [0, 360)
	float Normalized = FMath::Fmod(StickAngleDegrees, 360.0f);
	if (Normalized < 0.0f)
	{
		Normalized += 360.0f;
	}

	// 8 sectors: 45 degrees per sector
	SelectedSectorIndex = FMath::FloorToInt((Normalized + 22.5f) / 45.0f) % 8;

	switch (SelectedSectorIndex)
	{
	case 0:
		SelectedCommand = ETacticalCommandType::GarrettWireSnare;
		break;
	case 1:
		SelectedCommand = ETacticalCommandType::SerafinaAegisShield;
		break;
	case 2:
		SelectedCommand = ETacticalCommandType::LyraFlankVolley;
		break;
	case 3:
		SelectedCommand = ETacticalCommandType::CoordinatedStrike;
		break;
	case 4:
		SelectedCommand = ETacticalCommandType::FallBackToHeal;
		break;
	default:
		SelectedCommand = ETacticalCommandType::None;
		break;
	}
}
