// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenTripartiteFatigueBurnComponent.h"

UAshenTripartiteFatigueBurnComponent::UAshenTripartiteFatigueBurnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTripartiteFatigueBurnComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTripartiteFatigueBurnComponent::AccumulateFatigue(float GarrettDelta, float SerafinaDelta, float KaelenDelta)
{
	const float PrevGarrett  = GarrettControlFatigue;
	const float PrevSerafina = SerafinaPoiseFatigue;

	GarrettControlFatigue    = FMath::Clamp(GarrettControlFatigue + GarrettDelta, 0.0f, 1.0f);
	SerafinaPoiseFatigue     = FMath::Clamp(SerafinaPoiseFatigue + SerafinaDelta, 0.0f, 1.0f);
	KaelenTransferenceFatigue = FMath::Clamp(KaelenTransferenceFatigue + KaelenDelta, 0.0f, 1.0f);

	if (GarrettControlFatigue >= 0.70f && PrevGarrett < 0.70f && OnVulnerabilityTriggered.IsBound())
	{
		OnVulnerabilityTriggered.Broadcast("Garrett", GarrettControlFatigue);
		UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteFatigueBurnComponent: Garrett entered VULNERABLE state (Fatigue: %f)"), GarrettControlFatigue);
	}

	if (SerafinaPoiseFatigue >= 0.70f && PrevSerafina < 0.70f && OnVulnerabilityTriggered.IsBound())
	{
		OnVulnerabilityTriggered.Broadcast("Serafina", SerafinaPoiseFatigue);
		UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteFatigueBurnComponent: Serafina entered VULNERABLE state (Fatigue: %f)"), SerafinaPoiseFatigue);
	}
}

bool UAshenTripartiteFatigueBurnComponent::IsCompanionVulnerable(FName CompanionID) const
{
	if (CompanionID == "Garrett") return GarrettControlFatigue >= 0.70f;
	if (CompanionID == "Serafina") return SerafinaPoiseFatigue >= 0.70f;
	return false;
}
