// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTransferenceMirrorGASAbility.h"

UAshenTransferenceMirrorGASAbility::UAshenTransferenceMirrorGASAbility()
{
	BaseHealingAmount = 450.0f;
	BurnoutIncurredPercent = 0.25f;
}

bool UAshenTransferenceMirrorGASAbility::ExecuteTransferenceHeal(AActor* InstigatorActor, AActor* TargetHero)
{
	if (!InstigatorActor || !TargetHero) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTransferenceMirrorGASAbility: Transference Mended %.1f HP on %s (Serafina Incurred +%.0f%% Empathic Burnout)!"),
		BaseHealingAmount, *TargetHero->GetName(), BurnoutIncurredPercent * 100.0f);
	return true;
}
