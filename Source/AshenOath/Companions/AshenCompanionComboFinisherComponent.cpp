// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 404: Ashen Companion Combo Finisher Component

#include "AshenCompanionComboFinisherComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenCompanionComboFinisherComponent::UAshenCompanionComboFinisherComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionComboFinisherComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionComboFinisherComponent::ExecuteDualComboFinisher(FName CompanionID, AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;

	UAshenOath_HealthComponent* TargetHealth = TargetEnemy->FindComponentByClass<UAshenOath_HealthComponent>();
	if (TargetHealth && TargetHealth->GetHealthPercent() <= 0.20f)
	{
		const float FinisherDmg = 1200.0f;
		TargetHealth->ReceiveDamage(FinisherDmg, GetOwner());

		OnComboFinisherExecuted.Broadcast(CompanionID, FinisherDmg);

		UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionComboFinisherComponent: DUAL COMBO FINISHER EXECUTED WITH '%s' — Dealt %.0f lethal damage."),
			*CompanionID.ToString(), FinisherDmg);

		return true;
	}

	return false;
}
