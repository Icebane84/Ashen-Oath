// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenWeaveAegisNetGASAbility.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenWeaveAegisNetGASAbility::UAshenWeaveAegisNetGASAbility()
{
	AegisDurationSeconds = 6.0f;
	SerafinaFatigueCost = 0.15f;
}

bool UAshenWeaveAegisNetGASAbility::DeployAegisNetOnTarget(AActor* TargetCharacter)
{
	if (!TargetCharacter)
	{
		return false;
	}

	UWorld* World = TargetCharacter->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Grant HyperArmor on Target Poise Component
	if (UAshenOath_PoiseComponent* PoiseComp = TargetCharacter->FindComponentByClass<UAshenOath_PoiseComponent>())
	{
		PoiseComp->SetHyperArmorActive(true);
	}

	// 2. Add Serafina Fatigue
	if (UGameInstance* GI = World->GetGameInstance())
	{
		if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
		{
			FatigueSubsystem->AccumulateFatigue(TEXT("Serafina"), SerafinaFatigueCost);
		}
	}

	// 3. Modulate dynamic material golden filaments on target
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(TargetCharacter))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(1.0f, 0.85f, 0.3f, 1.0f), 3.0f);
	}

	if (OnAegisNetDeployed.IsBound())
	{
		OnAegisNetDeployed.Broadcast(TargetCharacter, AegisDurationSeconds, SerafinaFatigueCost);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaveAegisNetGASAbility: LUMINOUS AEGIS NET DEPLOYED on %s (Duration: %.1fs, HyperArmor: ON, +%.2f Serafina Fatigue)!"),
		*TargetCharacter->GetName(), AegisDurationSeconds, SerafinaFatigueCost);

	return true;
}
