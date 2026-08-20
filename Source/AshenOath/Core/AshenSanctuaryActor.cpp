#include "AshenSanctuaryActor.h"
#include "AshenCharacterInterface.h"
#include "AshenOathCharacter.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "AshenOath_ManaComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenSaveManager.h"
#include "Engine/World.h"

AAshenSanctuaryActor::AAshenSanctuaryActor()
{
	InteractionText = TEXT("Rest at Sanctuary");
}

void AAshenSanctuaryActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenSanctuaryActor::Interact_Implementation(APawn* Player)
{
	Super::Interact_Implementation(Player);

	if (!Player) return;

	// 1. Fully refill all player resources via character interface
	if (Player->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_HealthComponent* Health = IAshenCharacterInterface::Execute_GetHealthComponent(Player))
		{
			Health->Heal(Health->GetMaxHealth());
		}

		if (UAshenOath_StaminaComponent* Stamina = IAshenCharacterInterface::Execute_GetStaminaComponent(Player))
		{
			Stamina->SetCurrentStamina(Stamina->GetMaxStamina());
		}

		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(Player))
		{
			Sanity->SetCurrentSanity(Sanity->GetMaxSanity());
		}

		if (UAshenOath_ManaComponent* Mana = IAshenCharacterInterface::Execute_GetManaComponent(Player))
		{
			Mana->SetCurrentMana(Mana->GetMaxMana());
		}
	}

	// 2. Update player checkpoint spawn position
	if (AAshenOathCharacter* AshenChar = Cast<AAshenOathCharacter>(Player))
	{
		AshenChar->SpawnPosition = GetActorLocation();
	}

	// 3. Trigger psychological Heartstone integration ritual & clear imprint buffer
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		UGameInstance* GI = GetWorld()->GetGameInstance();
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			Kernel->InvokeIntegration(/*bForced=*/false);
		}

		// 4. Auto-save player progression
		if (UAshenSaveManager* SaveMgr = GI->GetSubsystem<UAshenSaveManager>())
		{
			SaveMgr->SaveGameData("AutoSave");
		}

		// 5. Emit world reset signals via the global bus
		if (UAshenOath_GameEventSubsystem* EventBus = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventBus->BroadcastSanctuaryRested();
		}
	}

	OnRested.Broadcast();
}

