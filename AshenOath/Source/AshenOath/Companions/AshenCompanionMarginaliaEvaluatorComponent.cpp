// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionMarginaliaEvaluatorComponent.h"

UAshenCompanionMarginaliaEvaluatorComponent::UAshenCompanionMarginaliaEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionMarginaliaEvaluatorComponent::EvaluateMarginalia(const FSoulStateVector& StateVector)
{
	if (StateVector.GarrettTrust >= 0.7f)
	{
		ActiveGarrettMarginalia = TEXT("Garrett: 'You charged again today. Let the trap do the bleeding next time.'");
	}
	else
	{
		ActiveGarrettMarginalia = TEXT("Garrett: 'Keep your guard up. I won't cover another blind charge.'");
	}

	if (StateVector.SerafinaTrust >= 0.7f)
	{
		ActiveSerafinaMarginalia = TEXT("Serafina: 'The corruption receded after accepting help. That matters.'");
	}
	else
	{
		ActiveSerafinaMarginalia = TEXT("Serafina: 'The shadow lingers near the bridge. Be careful.'");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionMarginaliaEvaluatorComponent: Evaluated marginalia successfully."));
}
