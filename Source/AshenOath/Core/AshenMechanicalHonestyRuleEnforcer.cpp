// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 628: Ashen Mechanical Honesty Rule Enforcer

#include "AshenMechanicalHonestyRuleEnforcer.h"

void UAshenMechanicalHonestyRuleEnforcer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAuditPasses = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenMechanicalHonestyRuleEnforcer: Initialized — Mechanical Honesty Rule Enforcer ONLINE (Rule of Mechanical Honesty)."));
}

bool UAshenMechanicalHonestyRuleEnforcer::ValidateMechanicalTruth(FName SystemName, float RawValue, float PresentedValue)
{
	TotalAuditPasses++;
	const bool bIsAuthentic = FMath::IsNearlyEqual(RawValue, PresentedValue, 0.001f);
	OnMechanicalHonestyAudited.Broadcast(SystemName, bIsAuthentic);

	if (!bIsAuthentic)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenMechanicalHonestyRuleEnforcer: VIOLATION DETECTED in '%s'! Raw: %.3f != Presented: %.3f."),
			*SystemName.ToString(), RawValue, PresentedValue);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenMechanicalHonestyRuleEnforcer: MECHANICAL TRUTH VERIFIED -> '%s' (Value: %.3f)."),
			*SystemName.ToString(), RawValue);
	}

	return bIsAuthentic;
}
