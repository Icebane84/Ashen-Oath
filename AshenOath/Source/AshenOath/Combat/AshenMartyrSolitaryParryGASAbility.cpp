// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMartyrSolitaryParryGASAbility.h"

UAshenMartyrSolitaryParryGASAbility::UAshenMartyrSolitaryParryGASAbility()
{
	ParryWindowBonusRatio = 0.10f;
	TrustDrainPerParry = 0.05f;
}

bool UAshenMartyrSolitaryParryGASAbility::ExecuteMartyrParry(float& OutTrustPenalty)
{
	OutTrustPenalty = TrustDrainPerParry;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrSolitaryParryGASAbility: MARTYR PARRY EXECUTED (+%.1f%% Windows, -%.1f%% Trust)!"),
		ParryWindowBonusRatio * 100.0f, OutTrustPenalty * 100.0f);
	return true;
}
