// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionTrustAccumulationComponent.h"

UAshenCompanionTrustAccumulationComponent::UAshenCompanionTrustAccumulationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionTrustAccumulationComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionTrustAccumulationComponent::ProcessProtectiveAction(FName CompanionID)
{
	if (CompanionID == "Garrett")
	{
		GarrettTrust = FMath::Clamp(GarrettTrust + 0.05f, 0.0f, 1.0f);
		if (OnTrustChanged.IsBound()) OnTrustChanged.Broadcast("Garrett", GarrettTrust);
	}
	else if (CompanionID == "Serafina")
	{
		SerafinaTrust = FMath::Clamp(SerafinaTrust + 0.05f, 0.0f, 1.0f);
		if (OnTrustChanged.IsBound()) OnTrustChanged.Broadcast("Serafina", SerafinaTrust);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustAccumulationComponent: Protective action processed for %s (Garrett: %f, Serafina: %f)"),
		*CompanionID.ToString(), GarrettTrust, SerafinaTrust);
}

void UAshenCompanionTrustAccumulationComponent::ProcessTacticalAbandonment(FName CompanionID)
{
	if (CompanionID == "Garrett")
	{
		GarrettTrust = FMath::Clamp(GarrettTrust - 0.10f, 0.0f, 1.0f);
		if (OnTrustChanged.IsBound()) OnTrustChanged.Broadcast("Garrett", GarrettTrust);
	}
	else if (CompanionID == "Serafina")
	{
		SerafinaTrust = FMath::Clamp(SerafinaTrust - 0.10f, 0.0f, 1.0f);
		if (OnTrustChanged.IsBound()) OnTrustChanged.Broadcast("Serafina", SerafinaTrust);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionTrustAccumulationComponent: Tactical abandonment processed for %s (Garrett: %f, Serafina: %f)"),
		*CompanionID.ToString(), GarrettTrust, SerafinaTrust);
}

void UAshenCompanionTrustAccumulationComponent::ProcessOathFulfilled()
{
	GarrettTrust  = FMath::Clamp(GarrettTrust  + 0.15f, 0.0f, 1.0f);
	SerafinaTrust = FMath::Clamp(SerafinaTrust + 0.15f, 0.0f, 1.0f);
	if (OnTrustChanged.IsBound())
	{
		OnTrustChanged.Broadcast("Garrett", GarrettTrust);
		OnTrustChanged.Broadcast("Serafina", SerafinaTrust);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustAccumulationComponent: Oath fulfilled! Both trusts boosted (Garrett: %f, Serafina: %f)"),
		GarrettTrust, SerafinaTrust);
}
