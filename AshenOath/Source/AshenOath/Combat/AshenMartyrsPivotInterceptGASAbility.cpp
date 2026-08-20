// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMartyrsPivotInterceptGASAbility.h"

UAshenMartyrsPivotInterceptGASAbility::UAshenMartyrsPivotInterceptGASAbility()
{
	LungeDistanceUnits = 450.0f;
}

bool UAshenMartyrsPivotInterceptGASAbility::ExecuteProtectiveLunge(AActor* KaelenActor, AActor* ProtectedCompanionActor)
{
	if (!KaelenActor || !ProtectedCompanionActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrsPivotInterceptGASAbility: MARTYR'S PIVOT LUNGE! Kaelen shoved %s to safety (Distance: %.1fuu)!"),
		*ProtectedCompanionActor->GetName(), LungeDistanceUnits);
	return true;
}
