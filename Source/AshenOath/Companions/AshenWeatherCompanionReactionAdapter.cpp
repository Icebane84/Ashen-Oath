// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenWeatherCompanionReactionAdapter.h"

UAshenWeatherCompanionReactionAdapter::UAshenWeatherCompanionReactionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeatherCompanionReactionAdapter::BeginPlay() { Super::BeginPlay(); }

FName UAshenWeatherCompanionReactionAdapter::EvaluateCompanionWeatherGear(FName CompanionID, EWeatherState Weather, float Toxicity)
{
	FName Gear = FName(TEXT("Gear.Standard"));
	if (Toxicity >= 0.50f || Weather == EWeatherState::VoidMiasma)
	{
		Gear = FName(TEXT("Gear.RespiratorMask"));
	}
	else if (Weather == EWeatherState::AshBlizzard)
	{
		Gear = FName(TEXT("Gear.HeavyAshCloak"));
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherCompanionReactionAdapter: Companion %s equipped '%s' (Weather: %d, Toxicity: %.2f)."),
		*CompanionID.ToString(), *Gear.ToString(), static_cast<int32>(Weather), Toxicity);

	return Gear;
}
