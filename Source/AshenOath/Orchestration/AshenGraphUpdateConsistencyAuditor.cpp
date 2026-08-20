// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 648: Ashen Graph Update Consistency Auditor (GUCA)

#include "AshenGraphUpdateConsistencyAuditor.h"

void UAshenGraphUpdateConsistencyAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalGUCAAuditsPassed = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenGraphUpdateConsistencyAuditor: Initialized — Graph Update Consistency Auditor (GUCA) ONLINE."));
}

bool UAshenGraphUpdateConsistencyAuditor::AuditNodeDrift(FName NodeID, int32 RuntimeStateHash, int32 GraphNodeHash)
{
	const bool bZeroDrift = (RuntimeStateHash == GraphNodeHash);
	if (bZeroDrift)
	{
		TotalGUCAAuditsPassed++;
	}

	OnGUCADriftAudited.Broadcast(NodeID, bZeroDrift);

	UE_LOG(LogTemp, Log, TEXT("UAshenGraphUpdateConsistencyAuditor: GUCA DRIFT AUDIT -> Node '%s' | Zero Drift: %s (Passed: %d)."),
		*NodeID.ToString(), bZeroDrift ? TEXT("TRUE [PASS]") : TEXT("FALSE [DRIFT DETECTED]"), TotalGUCAAuditsPassed);

	return bZeroDrift;
}
