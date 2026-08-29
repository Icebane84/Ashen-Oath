// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Core/AshenMartyrsTitheComponent.h"
#include "Combat/AshenOath_HealthComponent.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenMartyrsTitheComponent::UAshenMartyrsTitheComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalSacrificedHealth = 0.0f;
}

bool UAshenMartyrsTitheComponent::PerformMartyrSacrifice(float SacrificedMaxHealthAmount)
{
	if (SacrificedMaxHealthAmount <= 0.0f)
	{
		return false;
	}

	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return false;
	}

	UAshenOath_HealthComponent* HealthComp = Owner->FindComponentByClass<UAshenOath_HealthComponent>();
	if (!HealthComp)
	{
		return false;
	}

	const float CurrentMax = HealthComp->GetMaxHealth();
	if (CurrentMax - SacrificedMaxHealthAmount < 50.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrsTitheComponent: Sacrifice rejected - Cannot reduce Max HP below 50.0."));
		return false;
	}

	// 1. Permanently reduce Max Health
	HealthComp->SetMaxHealth(CurrentMax - SacrificedMaxHealthAmount);

	// 2. Accumulate sacrificed amount and calculate buff
	TotalSacrificedHealth += SacrificedMaxHealthAmount;
	const float BuffMultiplier = GetPartyBuffMultiplier();

	// 3. Restore +15.0% Companion Trust
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GI->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>())
			{
				TrustDirector->RestoreTrust(15.0f);
			}
		}
	}

	// 4. Update dynamic material instances on Kaelen
	if (AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Owner))
	{
		CombatChar->HandleRunicSeamColorUpdated(FLinearColor(0.85f, 0.05f, 0.15f, 1.0f), 3.0f);
	}

	OnMartyrTitheSacrificed.Broadcast(SacrificedMaxHealthAmount, BuffMultiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrsTitheComponent: MARTYR TITHE SACRIFICED (-%.0f Max HP -> New Max: %.0f) | Party Buff Multiplier: %.2fx | Trust Restored +15%%."),
		SacrificedMaxHealthAmount, HealthComp->GetMaxHealth(), BuffMultiplier);

	return true;
}
