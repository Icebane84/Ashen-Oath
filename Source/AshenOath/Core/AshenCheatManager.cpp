// AshenCheatManager.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenCheatManager.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenSanctuaryActor.h"
#include "AshenVigilRegistry.h"
#include "AshenCharacterInterface.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

void UAshenCheatManager::KillPlayer()
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
			{
				if (APawn* Player = Director->GetPlayerPawn())
				{
					UE_LOG(LogTemp, Warning, TEXT("Cheat KillPlayer: Applying fatal damage to player pawn to trigger death pipeline."));
					UGameplayStatics::ApplyDamage(Player, 9999.0f, nullptr, nullptr, nullptr);
				}

			}
		}
	}
}

void UAshenCheatManager::RestSanctuary()
{
	if (UWorld* World = GetWorld())
	{
		if (AActor* SanctuaryActor = UGameplayStatics::GetActorOfClass(World, AAshenSanctuaryActor::StaticClass()))
		{
			if (AAshenSanctuaryActor* Sanctuary = Cast<AAshenSanctuaryActor>(SanctuaryActor))
			{
				if (UAshenOath_DirectorSubsystem* Director = World->GetGameInstance()->GetSubsystem<UAshenOath_DirectorSubsystem>())
				{
					Sanctuary->Interact_Implementation(Director->GetPlayerPawn());
					UE_LOG(LogTemp, Log, TEXT("Cheat RestSanctuary: Rested at Sanctuary actor %s."), *Sanctuary->GetName());
				}
			}
		}
	}
}

void UAshenCheatManager::SetResolve(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				FSoulStateVector State = Kernel->GetStateVector();
				State.Resolve = FMath::Clamp(Value, 0.0f, 1.0f);
				Kernel->LoadSavedState(State, Kernel->GetDespairLevel());
				UE_LOG(LogTemp, Log, TEXT("Cheat SetResolve: Set Resolve to %.2f"), State.Resolve);
			}
		}
	}
}

void UAshenCheatManager::SetCorruption(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				FSoulStateVector State = Kernel->GetStateVector();
				State.Corruption = FMath::Clamp(Value, 0.0f, 1.0f);
				Kernel->LoadSavedState(State, Kernel->GetDespairLevel());
				UE_LOG(LogTemp, Log, TEXT("Cheat SetCorruption: Set Corruption to %.2f"), State.Corruption);
			}
		}
	}
}

void UAshenCheatManager::SetIsolation(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				FSoulStateVector State = Kernel->GetStateVector();
				State.Isolation = FMath::Clamp(Value, 0.0f, 1.0f);
				Kernel->LoadSavedState(State, Kernel->GetDespairLevel());
				UE_LOG(LogTemp, Log, TEXT("Cheat SetIsolation: Set Isolation to %.2f"), State.Isolation);
			}
		}
	}
}

void UAshenCheatManager::SetGarrettTrust(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				FSoulStateVector State = Kernel->GetStateVector();
				State.GarrettTrust = FMath::Clamp(Value, 0.0f, 1.0f);
				Kernel->LoadSavedState(State, Kernel->GetDespairLevel());
				UE_LOG(LogTemp, Log, TEXT("Cheat SetGarrettTrust: Set GarrettTrust to %.2f"), State.GarrettTrust);
			}
		}
	}
}

void UAshenCheatManager::SetSerafinaTrust(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				FSoulStateVector State = Kernel->GetStateVector();
				State.SerafinaTrust = FMath::Clamp(Value, 0.0f, 1.0f);
				Kernel->LoadSavedState(State, Kernel->GetDespairLevel());
				UE_LOG(LogTemp, Log, TEXT("Cheat SetSerafinaTrust: Set SerafinaTrust to %.2f"), State.SerafinaTrust);
			}
		}
	}
}

void UAshenCheatManager::SetDespair(float Value)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				Kernel->LoadSavedState(Kernel->GetStateVector(), FMath::Clamp(Value, 0.0f, 1.0f));
				UE_LOG(LogTemp, Log, TEXT("Cheat SetDespair: Set Despair to %.2f"), Value);
			}
		}
	}
}

void UAshenCheatManager::ProgressVigil(FString VigilID)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenVigilRegistry* Vigils = GI->GetSubsystem<UAshenVigilRegistry>())
			{
				Vigils->ProgressVigil(FName(*VigilID));
				UE_LOG(LogTemp, Log, TEXT("Cheat ProgressVigil: Advanced Vigil '%s'."), *VigilID);
			}
		}
	}
}

