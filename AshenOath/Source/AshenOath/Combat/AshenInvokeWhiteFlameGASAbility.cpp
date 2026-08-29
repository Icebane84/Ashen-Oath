// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenInvokeWhiteFlameGASAbility.h"
#include "Combat/AshenWhiteFlameResolutionSubsystem.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenInvokeWhiteFlameGASAbility::UAshenInvokeWhiteFlameGASAbility()
{
	CatharsisDurationSeconds = 12.0f;
	SanityHealAmount = 50.0f;
}

bool UAshenInvokeWhiteFlameGASAbility::InvokeWhiteFlame(
	AActor* KaelenActor,
	AActor* SerafinaActor,
	float KaelenResolve,
	float SerafinaBurnout)
{
	if (!KaelenActor)
	{
		return false;
	}

	UWorld* World = KaelenActor->GetWorld();
	if (!World)
	{
		return false;
	}

	UGameInstance* GI = World->GetGameInstance();
	if (!GI)
	{
		return false;
	}

	UAshenWhiteFlameResolutionSubsystem* WhiteFlameSubsystem = GI->GetSubsystem<UAshenWhiteFlameResolutionSubsystem>();
	if (!WhiteFlameSubsystem)
	{
		return false;
	}

	// 1. Evaluate priming conditions
	if (!WhiteFlameSubsystem->EvaluateResolutionReadiness(KaelenResolve, SerafinaBurnout))
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenInvokeWhiteFlameGASAbility: Failed activation - Conditions not primed (Resolve: %.2f, Burnout: %.2f)."),
			KaelenResolve, SerafinaBurnout);
		return false;
	}

	// 2. Activate White Flame Resolution via world context
	float ClearedDebt = 0.0f;
	if (!WhiteFlameSubsystem->ActivateWhiteFlameWithWorldContext(World, ClearedDebt))
	{
		return false;
	}

	// 3. Heal Kaelen's Sanity
	AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(KaelenActor);
	if (CombatChar)
	{
		if (UAshenOath_SanityComponent* Sanity = CombatChar->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			Sanity->HealSanity(SanityHealAmount);
		}

		// Update dynamic weapon fuller emissives to pure White Flame
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(0.95f, 0.98f, 1.0f, 1.0f), 5.0f);
	}

	if (OnWhiteFlameInvoked.IsBound())
	{
		OnWhiteFlameInvoked.Broadcast(ClearedDebt, SanityHealAmount, CatharsisDurationSeconds);
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenInvokeWhiteFlameGASAbility: *** THE WHITE FLAME RESOLUTION HAS BEEN INVOKED *** (Cleared Debt: %.2f | Sanity Healed: +%.1f | Duration: %.1fs)!"),
		ClearedDebt, SanityHealAmount, CatharsisDurationSeconds);
	return true;
}
