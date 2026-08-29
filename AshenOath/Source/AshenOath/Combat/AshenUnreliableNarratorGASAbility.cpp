// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNarratorGASAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_StaminaComponent.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Core/AshenUnreliableStateMachineSubsystem.h"
#include "Engine/World.h"

UAshenUnreliableNarratorGASAbility::UAshenUnreliableNarratorGASAbility()
{
	StaminaCost = 15.0f;
	SanityClarityHeal = 15.0f;
}

bool UAshenUnreliableNarratorGASAbility::DispelHallucinatoryMirage(AActor* InstigatorActor)
{
	if (!InstigatorActor)
	{
		return false;
	}

	UWorld* World = InstigatorActor->GetWorld();
	if (!World)
	{
		return false;
	}

	// 1. Validate and consume stamina
	UAshenOath_StaminaComponent* StaminaComp = InstigatorActor->FindComponentByClass<UAshenOath_StaminaComponent>();
	if (!StaminaComp)
	{
		return false;
	}

	if (StaminaComp->GetCurrentStamina() < StaminaCost)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableNarratorGASAbility: Insufficient stamina to release willpower pulse (Current: %.1f, Required: %.1f)."),
			StaminaComp->GetCurrentStamina(), StaminaCost);
		return false;
	}

	StaminaComp->ConsumeStamina(StaminaCost);

	// 2. Heal sanity mental clarity
	if (UAshenOath_SanityComponent* SanityComp = InstigatorActor->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		SanityComp->HealSanity(SanityClarityHeal);
	}

	// 3. Reset Unreliable UI State Machine back to DiegeticOnly
	if (UAshenUnreliableStateMachineSubsystem* StateSubsystem = World->GetSubsystem<UAshenUnreliableStateMachineSubsystem>())
	{
		StateSubsystem->SetInterfaceMode(EAshenInterfaceMode::DiegeticOnly);
	}

	// 4. Modulate weapon fuller clarity pulse
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(InstigatorActor))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(0.8f, 0.9f, 1.0f, 1.0f), 2.0f);
	}

	if (OnMirageDispelled.IsBound())
	{
		OnMirageDispelled.Broadcast(StaminaCost, SanityClarityHeal);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableNarratorGASAbility: Willpower pulse dispelled active mirages! (-%.1f Stamina, +%.1f Sanity, Interface -> DiegeticOnly)."),
		StaminaCost, SanityClarityHeal);

	return true;
}
