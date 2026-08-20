// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_ParticleBudgetHUD.h"

void UAshenUserWidget_ParticleBudgetHUD::UpdateParticleBudget(int32 CurrentCount, int32 MaxCap)
{
	ActiveParticleCount = CurrentCount;
	bIsBudgetExceeded = (ActiveParticleCount > MaxCap);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ParticleBudgetHUD: Particle Count: %d / %d (Budget Exceeded: %s)"),
		ActiveParticleCount, MaxCap, bIsBudgetExceeded ? TEXT("TRUE") : TEXT("FALSE"));
}
