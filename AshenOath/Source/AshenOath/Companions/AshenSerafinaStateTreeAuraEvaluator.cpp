// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaStateTreeAuraEvaluator.h"

UAshenSerafinaStateTreeAuraEvaluator::UAshenSerafinaStateTreeAuraEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenSerafinaStateTreeAuraEvaluator::ShouldActivateAura(float SerafinaTrust, float PlayerHealthPct) const
{
	bool bActivate = (SerafinaTrust >= 0.4f) && (PlayerHealthPct <= 0.6f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaStateTreeAuraEvaluator: Aura activation evaluated to %s"), bActivate ? TEXT("TRUE") : TEXT("FALSE"));
	return bActivate;
}
