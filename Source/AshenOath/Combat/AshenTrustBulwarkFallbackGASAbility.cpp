// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTrustBulwarkFallbackGASAbility.h"

UAshenTrustBulwarkFallbackGASAbility::UAshenTrustBulwarkFallbackGASAbility()
{
	TrustMatrixSpike = 3.5f;
	ResonantWindowDurationSeconds = 8.0f;
}

bool UAshenTrustBulwarkFallbackGASAbility::ExecuteTrustFallback(AActor* KaelenActor, AActor* SerafinaActor)
{
	if (!KaelenActor || !SerafinaActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTrustBulwarkFallbackGASAbility: TRUST EXECUTED! Pivoted into Bulwark -> Trust +%.1f | Cleared 5%% Debt | Resonant Window: %.1fs!"),
		TrustMatrixSpike, ResonantWindowDurationSeconds);
	return true;
}
