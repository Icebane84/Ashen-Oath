// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 523: Ashen Companion Tactical Cover Subsystem

#include "AshenCompanionTacticalCoverSubsystem.h"

void UAshenCompanionTacticalCoverSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTacticalCoverSubsystem: Initialized — Companion Tactical Cover Engine ONLINE."));
}

FVector UAshenCompanionTacticalCoverSubsystem::FindOptimalTacticalCover(FName CompanionID, FVector OriginLocation, float MaxSearchRadius)
{
	const FVector Offset = (CompanionID == FName(TEXT("Companion_Garrett"))) ? FVector(300, 300, 0) : FVector(-300, 300, 0);
	const FVector CoverPoint = OriginLocation + Offset;

	OnCoverAssigned.Broadcast(CompanionID, CoverPoint);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionTacticalCoverSubsystem: TACTICAL COVER ASSIGNED -> Companion '%s' at Location (%s)."),
		*CompanionID.ToString(), *CoverPoint.ToString());

	return CoverPoint;
}
