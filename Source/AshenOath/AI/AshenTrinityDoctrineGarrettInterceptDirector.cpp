// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 806: Ashen Trinity Doctrine Garrett Intercept Director

#include "AshenTrinityDoctrineGarrettInterceptDirector.h"

FVector UAshenTrinityDoctrineGarrettInterceptDirector::EvaluateGarrettInterceptPosition(FVector KaelenLocation, FVector RearBlindSpotDirection, float GarrettTrustLevel)
{
	const bool bHighTrust = (GarrettTrustLevel >= 60.0f);
	const FVector InterceptPos = bHighTrust ? (KaelenLocation + (RearBlindSpotDirection * 300.0f)) : KaelenLocation;

	OnGarrettInterceptEvaluated.Broadcast(InterceptPos, bHighTrust);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTrinityDoctrineGarrettInterceptDirector: GARRETT INTERCEPT EVALUATED -> Trust: %.1f%% | Intercept Active: %s | Position: (%s)."),
		GarrettTrustLevel, bHighTrust ? TEXT("TRUE (Rear Arc Flank)") : TEXT("FALSE (Hesitating)"), *InterceptPos.ToString());

	return InterceptPos;
}
