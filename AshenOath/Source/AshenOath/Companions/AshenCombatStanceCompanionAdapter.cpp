// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCombatStanceCompanionAdapter.h"

UAshenCombatStanceCompanionAdapter::UAshenCombatStanceCompanionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCombatStanceCompanionAdapter::BeginPlay() { Super::BeginPlay(); }

FName UAshenCombatStanceCompanionAdapter::GetCompanionSynergyRole(FName CompanionID, ECombatStance PlayerStance)
{
	FName Role = FName(TEXT("Role.DefaultSupport"));
	if (PlayerStance == ECombatStance::Berserk)
	{
		if (CompanionID == FName(TEXT("Garrett"))) Role = FName(TEXT("Role.ThreatDrawTaunt"));
		else if (CompanionID == FName(TEXT("Serafina"))) Role = FName(TEXT("Role.AggressiveBurnNova"));
	}
	else if (PlayerStance == ECombatStance::Aegis)
	{
		if (CompanionID == FName(TEXT("Garrett"))) Role = FName(TEXT("Role.FlankAssassinate"));
		else if (CompanionID == FName(TEXT("Serafina"))) Role = FName(TEXT("Role.PoiseReinforcement"));
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceCompanionAdapter: Companion %s assigned role '%s' for Player Stance %d."),
		*CompanionID.ToString(), *Role.ToString(), static_cast<int32>(PlayerStance));

	return Role;
}
