// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 644: Ashen CAN Empathic Burnout Component

#include "AshenCANEmpathicBurnoutComponent.h"

UAshenCANEmpathicBurnoutComponent::UAshenCANEmpathicBurnoutComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveBurnoutLevel = 0.0f;
}

void UAshenCANEmpathicBurnoutComponent::AccrueEmpathicBurnout(float DeltaBurnout)
{
	ActiveBurnoutLevel = FMath::Clamp(ActiveBurnoutLevel + DeltaBurnout, 0.0f, 100.0f);
	const float HealingEfficiency = 1.0f - (ActiveBurnoutLevel / 200.0f);

	OnBurnoutEvaluated.Broadcast(ActiveBurnoutLevel, HealingEfficiency);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANEmpathicBurnoutComponent: EMPATHIC BURNOUT ACCRUED -> Level: %.1f | Healing Efficiency: %.2fx (can-empathic_burnout)."),
		ActiveBurnoutLevel, HealingEfficiency);
}
