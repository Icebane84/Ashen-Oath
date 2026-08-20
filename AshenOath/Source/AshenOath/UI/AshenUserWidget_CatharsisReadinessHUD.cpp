// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CatharsisReadinessHUD.h"

void UAshenUserWidget_CatharsisReadinessHUD::UpdateConvergenceReadiness(float Resolve, float Burnout)
{
	bIsCatharsisReady = (Resolve >= 0.90f && Burnout >= 0.65f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CatharsisReadinessHUD: Resolve: %.2f | Burnout: %.2f -> Ready: %s"),
		Resolve, Burnout, bIsCatharsisReady ? TEXT("TRUE") : TEXT("FALSE"));
}
