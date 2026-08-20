// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_SympatheticTetherHUD.h"

void UAshenUserWidget_SympatheticTetherHUD::UpdateTetherState(bool bActive, float Tension)
{
	bIsTetherVisible = bActive;
	TetherTension = FMath::Clamp(Tension, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SympatheticTetherHUD: Sympathetic Tether %s (Tension: %.2f)"),
		bIsTetherVisible ? TEXT("ACTIVE") : TEXT("SEVERED"), TetherTension);
}
