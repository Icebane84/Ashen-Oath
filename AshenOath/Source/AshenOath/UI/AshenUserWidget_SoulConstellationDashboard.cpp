// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SoulConstellationDashboard.h"

void UAshenUserWidget_SoulConstellationDashboard::RefreshSoulConstellationDashboard(FAshenIdentityStateVector StateVector)
{
	DisplayedStateVector = StateVector;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulConstellationDashboard: Dashboard refreshed — Debt=%f Stage=%d Stance=%d Empathic=%d Tactical=%d"),
		DisplayedStateVector.IntegrationDebt,
		(int32)DisplayedStateVector.DebtStage,
		(int32)DisplayedStateVector.CompiledProfile.StanceProfile,
		(int32)DisplayedStateVector.CompiledProfile.EmpathicProfile,
		(int32)DisplayedStateVector.CompiledProfile.TacticalProfile);
}

