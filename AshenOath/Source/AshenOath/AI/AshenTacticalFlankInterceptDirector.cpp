// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 674: Ashen Tactical Flank Intercept Director

#include "AshenTacticalFlankInterceptDirector.h"

void UAshenTacticalFlankInterceptDirector::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalFlankInterceptsDirected = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenTacticalFlankInterceptDirector: Initialized — Tactical Flank Intercept Director ONLINE."));
}

void UAshenTacticalFlankInterceptDirector::DirectGarrettTacticalFlank(FName FlankEnemyID, bool bIsKaelenUnbroken)
{
	if (FlankEnemyID.IsNone()) return;

	TotalFlankInterceptsDirected++;
	const bool bProtected = bIsKaelenUnbroken;
	OnTacticalFlankExecuted.Broadcast(FlankEnemyID, bProtected);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalFlankInterceptDirector: GARRETT TACTICAL FLANK INTERCEPT DIRECTED -> Target Enemy '%s' | EQS Blind-Spot Protected: %s (Total: %d)."),
		*FlankEnemyID.ToString(), bProtected ? TEXT("TRUE [UNBROKEN TAG]") : TEXT("FALSE"), TotalFlankInterceptsDirected);
}
