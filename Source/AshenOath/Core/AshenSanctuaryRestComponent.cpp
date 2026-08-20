// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSanctuaryRestComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenOath_TrustAccumulationComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

UAshenSanctuaryRestComponent::UAshenSanctuaryRestComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsResting = false;
}

void UAshenSanctuaryRestComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSanctuaryRestComponent::InitiateRestSequence(AActor* PlayerPawn)
{
	if (!PlayerPawn || bIsResting)
	{
		return false;
	}

	bIsResting = true;
	OnRestStarted.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryRestComponent: Campfire Rest Sequence Initiated!"));

	// 1. Restore Core Resources to 100% Max
	if (UAshenOath_HealthComponent* Health = PlayerPawn->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		Health->Heal(Health->GetMaxHealth());
	}

	if (UAshenOath_StaminaComponent* Stamina = PlayerPawn->FindComponentByClass<UAshenOath_StaminaComponent>())
	{
		Stamina->SetCurrentStamina(Stamina->GetMaxStamina());
	}

	if (UAshenOath_ManaComponent* Mana = PlayerPawn->FindComponentByClass<UAshenOath_ManaComponent>())
	{
		Mana->SetCurrentMana(Mana->GetMaxMana());
	}

	if (UAshenOath_SanityComponent* Sanity = PlayerPawn->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		Sanity->SetCurrentSanity(Sanity->GetMaxSanity());
	}

	// 2. Consolidate Identity Imprints on Imprint Buffer
	float ConsolidatedDebt = 0.0f;
	if (UAshenOath_ImprintBufferComponent* Buffer = PlayerPawn->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
	{
		ConsolidatedDebt = Buffer->GetIntegrationDebt();
		Buffer->ConsumeBuffer(); // Imprints integrated into Heartstone memory
		UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryRestComponent: Consolidated %.2f Integration Debt"), ConsolidatedDebt);
	}

	// 3. Check Companion Rest Dialogue Triggers
	CheckCompanionRestDialogueTriggers(PlayerPawn);

	bIsResting = false;
	OnRestCompleted.Broadcast(ConsolidatedDebt);
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryRestComponent: Campfire Rest Sequence Completed successfully."));

	return true;
}

float UAshenSanctuaryRestComponent::RetrieveEmberEcho(AActor* PlayerPawn, float LostEmbersAmount)
{
	if (!PlayerPawn || LostEmbersAmount <= 0.0f)
	{
		return 0.0f;
	}

	if (UAshenOath_CurrencyComponent* Currency = PlayerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>())
	{
		Currency->AddEmbers(LostEmbersAmount);
		OnEmberEchoRetrieved.Broadcast(LostEmbersAmount);
		UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryRestComponent: Ember Echo retrieved! +%.0f Embers"), LostEmbersAmount);
		return LostEmbersAmount;
	}

	return 0.0f;
}

void UAshenSanctuaryRestComponent::CheckCompanionRestDialogueTriggers(AActor* PlayerPawn)
{
	if (!PlayerPawn) { return; }

	if (UAshenOath_TrustAccumulationComponent* Trust = PlayerPawn->FindComponentByClass<UAshenOath_TrustAccumulationComponent>())
	{
		float KaelenGarrettTrust = Trust->GarrettTrustAccumulator;
		float KaelenSerafinaTrust = Trust->SerafinaTrustAccumulator;
		float GarrettSerafinaTrust = (Trust->GarrettTrustAccumulator + Trust->SerafinaTrustAccumulator) * 0.5f;

		UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryRestComponent: Rest Dialogue Check — Kaelen->Garrett: %.2f | Kaelen->Serafina: %.2f | Garrett->Serafina: %.2f"),
			KaelenGarrettTrust, KaelenSerafinaTrust, GarrettSerafinaTrust);
	}
}
