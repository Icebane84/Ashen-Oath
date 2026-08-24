// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTraumaSomaticsSaveGameAdapter.h"

UAshenTraumaSomaticsSaveGameAdapter::UAshenTraumaSomaticsSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedVeinCorruption = 0.0f;
	SavedBladeSoot = 0.0f;
	SavedMicroNicks = 0;
	SavedHeartBPM = 60.0f;
}

void UAshenTraumaSomaticsSaveGameAdapter::PackageSomatics(
	float VeinCorruption,
	float BladeSoot,
	int32 MicroNicks,
	float HeartBPM)
{
	SavedVeinCorruption = VeinCorruption;
	SavedBladeSoot = BladeSoot;
	SavedMicroNicks = MicroNicks;
	SavedHeartBPM = HeartBPM;
	bHasSavedData = true;
}

bool UAshenTraumaSomaticsSaveGameAdapter::RestoreSomatics(
	float& OutVeinCorruption,
	float& OutBladeSoot,
	int32& OutMicroNicks,
	float& OutHeartBPM)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutVeinCorruption = SavedVeinCorruption;
	OutBladeSoot = SavedBladeSoot;
	OutMicroNicks = SavedMicroNicks;
	OutHeartBPM = SavedHeartBPM;
	return true;
}
