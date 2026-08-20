// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 638: Ashen Dual Layer Schema Contract Auditor

#include "AshenDualLayerSchemaContractAuditor.h"

void UAshenDualLayerSchemaContractAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalParityAudits = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenDualLayerSchemaContractAuditor: Initialized — Dual Layer Schema Contract Auditor ONLINE (Zod <-> C++ Parity)."));
}

bool UAshenDualLayerSchemaContractAuditor::AuditStatParity(FName StatName, float ZodSchemaValue, float CPlusPlusValue)
{
	TotalParityAudits++;
	const bool bParity = FMath::IsNearlyEqual(ZodSchemaValue, CPlusPlusValue, 0.001f);
	OnSchemaAudited.Broadcast(StatName, bParity);

	UE_LOG(LogTemp, Log, TEXT("UAshenDualLayerSchemaContractAuditor: STAT PARITY AUDIT -> '%s' | Zod: %.2f == C++: %.2f -> %s (Audit #%d)."),
		*StatName.ToString(), ZodSchemaValue, CPlusPlusValue, bParity ? TEXT("PASS") : TEXT("FAIL"), TotalParityAudits);

	return bParity;
}
