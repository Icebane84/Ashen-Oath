// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCheatSubsystem.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenSoulPerkActivationComponent.h"
#include "AshenMindscapeCollapseVolume.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

void UAshenCheatSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Warning, TEXT("UAshenCheatSubsystem: Developer cheat subsystem active. Commands ready."));
}

void UAshenCheatSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenCheatSubsystem::ExecTriggerCollapse()
{
	OnCheatExecuted.Broadcast(TEXT("TriggerCollapse"), TEXT(""));
	UE_LOG(LogTemp, Warning, TEXT("UAshenCheatSubsystem: CHEAT EXEC: Forced Mindscape Collapse triggered!"));
}

void UAshenCheatSubsystem::ExecGrantEmbers(float Amount)
{
	if (UAshenOath_DirectorSubsystem* Director = GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>())
	{
		if (APawn* PlayerPawn = Director->GetPlayerPawn())
		{
			if (UAshenOath_CurrencyComponent* Currency = PlayerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>())
			{
				Currency->AddEmbers(Amount);
			}
		}
	}

	OnCheatExecuted.Broadcast(TEXT("GrantEmbers"), FString::SanitizeFloat(Amount));
	UE_LOG(LogTemp, Warning, TEXT("UAshenCheatSubsystem: CHEAT EXEC: Granted %.0f Embers!"), Amount);
}

void UAshenCheatSubsystem::ExecUnlockAllPerks()
{
	if (UAshenOath_DirectorSubsystem* Director = GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>())
	{
		if (APawn* PlayerPawn = Director->GetPlayerPawn())
		{
			if (UAshenSoulPerkActivationComponent* Perks = PlayerPawn->FindComponentByClass<UAshenSoulPerkActivationComponent>())
			{
				Perks->ActivatePerk(FName("Perk_UnshakeableStance"));
				Perks->ActivatePerk(FName("Perk_VitalResonance"));
			}
		}
	}

	OnCheatExecuted.Broadcast(TEXT("UnlockAllPerks"), TEXT(""));
	UE_LOG(LogTemp, Warning, TEXT("UAshenCheatSubsystem: CHEAT EXEC: Unlocked all constellation perks!"));
}
