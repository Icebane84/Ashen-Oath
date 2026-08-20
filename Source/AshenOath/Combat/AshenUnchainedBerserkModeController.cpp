// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 666: Ashen Unchained Berserk Mode Controller

#include "AshenUnchainedBerserkModeController.h"

void UAshenUnchainedBerserkModeController::EngageUnchainedBerserkMode()
{
	bIsUnchainedActive = true;
	const float SpeedMult = 3.0f; // +200% (3.0x multiplier)
	const bool bNoHitStop = true;

	OnBerserkUpdated.Broadcast(SpeedMult, bNoHitStop);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUnchainedBerserkModeController: UNCHAINED BERSERK ENGAGED -> Attack Speed: 3.0x (+200%%) | Hit-Stop: REMOVED | Erasure Stance ACTIVE."));
}
