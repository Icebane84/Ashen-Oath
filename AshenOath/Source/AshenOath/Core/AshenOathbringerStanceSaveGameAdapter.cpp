// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenOathbringerStanceSaveGameAdapter.h"

UAshenOathbringerStanceSaveGameAdapter::UAshenOathbringerStanceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedStance = EOathbringerMartialStance::VomTag_HighWrath;
	SavedFlowCharge = 0.0f;
	SavedMasteredCount = 0;
}

void UAshenOathbringerStanceSaveGameAdapter::PackageStanceState(
	EOathbringerMartialStance ActiveStance,
	float FlowCharge,
	int32 MasteredStancesCount)
{
	SavedStance = ActiveStance;
	SavedFlowCharge = FlowCharge;
	SavedMasteredCount = MasteredStancesCount;
	bHasSavedData = true;
}

bool UAshenOathbringerStanceSaveGameAdapter::RestoreStanceState(
	EOathbringerMartialStance& OutStance,
	float& OutFlowCharge,
	int32& OutMasteredCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutStance = SavedStance;
	OutFlowCharge = SavedFlowCharge;
	OutMasteredCount = SavedMasteredCount;
	return true;
}
