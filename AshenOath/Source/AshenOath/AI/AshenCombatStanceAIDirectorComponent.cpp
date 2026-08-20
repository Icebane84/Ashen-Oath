// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenCombatStanceAIDirectorComponent.h"

UAshenCombatStanceAIDirectorComponent::UAshenCombatStanceAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCombatStanceAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

FName UAshenCombatStanceAIDirectorComponent::EvaluateEnemyTacticalResponse(ECombatStance PlayerStance)
{
	FName AIResponse = FName(TEXT("Tactics.StandardMelee"));
	switch (PlayerStance)
	{
	case ECombatStance::Berserk:
		AIResponse = FName(TEXT("Tactics.MaintainDistanceAndParry"));
		break;
	case ECombatStance::Aegis:
		AIResponse = FName(TEXT("Tactics.AggressiveFlankEncircle"));
		break;
	case ECombatStance::Flow:
	default:
		AIResponse = FName(TEXT("Tactics.StandardMelee"));
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceAIDirectorComponent: Enemy tactical response set to '%s' against Player Stance %d."),
		*AIResponse.ToString(), static_cast<int32>(PlayerStance));

	return AIResponse;
}
