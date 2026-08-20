// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/GA_SerafinaEmpathicConduitNova.h"

UGA_SerafinaEmpathicConduitNova::UGA_SerafinaEmpathicConduitNova()
{
	SyncRange = 1200.0f;
	BaseNovaDamage = 750.0f;
	NovaRadius = 600.0f;
}

bool UGA_SerafinaEmpathicConduitNova::InitiateConduitChannel(AActor* SerafinaActor, AActor* KaelenActor, AActor* TargetEnemy, float ActiveBurnout)
{
	if (!SerafinaActor || !KaelenActor || !TargetEnemy) return false;
	if (ActiveBurnout < 0.70f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaEmpathicConduitNova: Cannot activate, Burnout (%.2f) is below 0.70 threshold."), ActiveBurnout);
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("UGA_SerafinaEmpathicConduitNova: EMPATHIC CONDUIT NOVA CHANNEL ACTIVE! Serafina channeling %.1f%% Burnout into %s with Kaelen."),
		ActiveBurnout * 100.0f, *TargetEnemy->GetName());
	return true;
}
