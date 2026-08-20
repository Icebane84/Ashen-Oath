// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 664: Ashen Martyr Guard Ally Intercept Component

#include "AshenMartyrGuardAllyInterceptComponent.h"

UAshenMartyrGuardAllyInterceptComponent::UAshenMartyrGuardAllyInterceptComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalLethalInterceptsExecuted = 0;
}

void UAshenMartyrGuardAllyInterceptComponent::InterceptLethalBlowForAlly(AActor* ProtectedAlly, float DamageToIntercept)
{
	if (!ProtectedAlly) return;

	TotalLethalInterceptsExecuted++;
	const float Cost = DamageToIntercept * 0.5f;
	OnInterceptExecuted.Broadcast(ProtectedAlly, Cost);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrGuardAllyInterceptComponent: MARTYR'S GUARD LETHAL INTERCEPT -> Protected Ally '%s' | Intercept Cost: %.1f stamina (Total: %d)."),
		*ProtectedAlly->GetName(), Cost, TotalLethalInterceptsExecuted);
}
