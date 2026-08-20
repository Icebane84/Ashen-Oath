// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenBehavioralProfileCompiler.h"

UAshenBehavioralProfileCompiler::UAshenBehavioralProfileCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenBehavioralProfileCompiler::BeginPlay() { Super::BeginPlay(); }

FAshenBehavioralProfile UAshenBehavioralProfileCompiler::CompileProfileFromWeights(float Stance, float Empathic, float Tactical)
{
	FAshenBehavioralProfile Profile;
	Profile.StanceProfile   = Stance   >= 0.70f ? EAshenStanceProfile::Resolved_Protector   : Stance   >= 0.50f ? EAshenStanceProfile::Reckless_Avenger : Stance   >= 0.30f ? EAshenStanceProfile::Cynical_Isolated   : EAshenStanceProfile::Fractured_Reactive;
	Profile.EmpathicProfile = Empathic >= 0.70f ? EAshenEmpathicProfile::Open_Compassionate : Empathic >= 0.50f ? EAshenEmpathicProfile::Guarded_Transactional : Empathic >= 0.30f ? EAshenEmpathicProfile::Burned_Out : EAshenEmpathicProfile::Dissociated_Hollow;
	Profile.TacticalProfile = Tactical >= 0.70f ? EAshenTacticalProfile::Methodical_Calculated : Tactical >= 0.50f ? EAshenTacticalProfile::Aggressive_Volatile : Tactical >= 0.30f ? EAshenTacticalProfile::Evasive_Cautious : EAshenTacticalProfile::Paralyzed_Overwhelmed;
	UE_LOG(LogTemp, Log, TEXT("UAshenBehavioralProfileCompiler: Compiled profile — Stance=%d Empathic=%d Tactical=%d"), (int32)Profile.StanceProfile, (int32)Profile.EmpathicProfile, (int32)Profile.TacticalProfile);
	return Profile;
}
