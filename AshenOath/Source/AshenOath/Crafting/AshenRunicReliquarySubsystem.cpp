// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Crafting/AshenRunicReliquarySubsystem.h"

UAshenRunicReliquarySubsystem::UAshenRunicReliquarySubsystem()
{
}

void UAshenRunicReliquarySubsystem::RegisterAcquiredRune(const FRunicSocketEntry& RuneEntry)
{
	if (RuneEntry.RuneId != NAME_None)
	{
		AcquiredRunes.Add(RuneEntry.RuneId, RuneEntry);
	}
}

bool UAshenRunicReliquarySubsystem::SocketRune(const FName& WeaponId, const FRunicSocketEntry& RuneEntry)
{
	if (WeaponId == NAME_None || RuneEntry.RuneId == NAME_None)
	{
		return false;
	}

	FSoulForgeWeaponState& State = WeaponStates.FindOrAdd(WeaponId);
	State.WeaponId = WeaponId;
	State.ActiveSocketCount++;
	State.EffectiveMassKg = FMath::Clamp(State.BaseMassKg + RuneEntry.MassModifierKg, 45.0f, 220.0f);
	State.TotalPoiseMultiplier *= RuneEntry.PoiseMultiplier;

	if (RuneEntry.AttunementTier == ESoulForgeAttunementTier::MasterForged)
	{
		State.bHasBossCoreInfusion = true;
	}

	OnRuneSocketed.Broadcast(WeaponId, RuneEntry);
	OnWeaponAttunementUpdated.Broadcast(State);
	return true;
}

FSoulForgeWeaponState UAshenRunicReliquarySubsystem::GetWeaponState(const FName& WeaponId) const
{
	if (const FSoulForgeWeaponState* Found = WeaponStates.Find(WeaponId))
	{
		return *Found;
	}

	FSoulForgeWeaponState DefaultState;
	DefaultState.WeaponId = WeaponId;
	return DefaultState;
}
