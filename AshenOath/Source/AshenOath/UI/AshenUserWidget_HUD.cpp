// Copyright Phoenix Protocol. All rights reserved.

#include "AshenUserWidget_HUD.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_StatsComponent.h"
#include "AshenOath_DirectorSubsystem.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

void UAshenUserWidget_HUD::NativeConstruct()
{
	Super::NativeConstruct();

	InitializeHUD();

	UWorld* World = GetWorld();
	if (!World) return;

	UGameInstance* GI = World->GetGameInstance();
	if (!GI) return;

	UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>();
	if (!Director) return;

	APawn* PlayerPawn = Director->GetPlayerPawn();
	if (!PlayerPawn)
	{
		PlayerPawn = GetOwningPlayerPawn();
	}

	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_HealthComponent* Health = IAshenCharacterInterface::Execute_GetHealthComponent(PlayerPawn);
		if (Health)
		{
			Health->OnHealthChanged.AddDynamic(this, &UAshenUserWidget_HUD::HandleHealthChanged);
		}

		UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn);
		if (Stats)
		{
			Stats->OnXpGained.AddDynamic(this, &UAshenUserWidget_HUD::HandleXpGained);
			Stats->OnLevelUp.AddDynamic(this, &UAshenUserWidget_HUD::HandleLevelUp);
		}
	}
}

void UAshenUserWidget_HUD::HandleHealthChanged(float CurrentHealth, float MaxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(MaxHealth > 0.0f ? (CurrentHealth / MaxHealth) : 0.0f);
	}
}

void UAshenUserWidget_HUD::HandleXpGained(int32 AmountGained, int32 TotalXp)
{
	if (!XPBar) return;

	APawn* PlayerPawn = GetOwningPlayerPawn();
	if (!PlayerPawn)
	{
		if (UWorld* World = GetWorld())
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
				{
					PlayerPawn = Director->GetPlayerPawn();
				}
			}
		}
	}

	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn);
		if (Stats)
		{
			float Req = Stats->GetXpRequirement();
			XPBar->SetPercent(Req > 0.0f ? (static_cast<float>(TotalXp) / Req) : 0.0f);
		}
	}
}

void UAshenUserWidget_HUD::HandleLevelUp(int32 NewLevel)
{
	if (LevelText)
	{
		LevelText->SetText(FText::FromString(FString::Printf(TEXT("LVL %d"), NewLevel)));
	}
}

void UAshenUserWidget_HUD::InitializeHUD()
{
	APawn* PlayerPawn = GetOwningPlayerPawn();
	if (!PlayerPawn)
	{
		if (UWorld* World = GetWorld())
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
				{
					PlayerPawn = Director->GetPlayerPawn();
				}
			}
		}
	}

	if (PlayerPawn && PlayerPawn->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_HealthComponent* Health = IAshenCharacterInterface::Execute_GetHealthComponent(PlayerPawn);
		if (Health && HealthBar)
		{
			float MaxH = Health->GetMaxHealth();
			HealthBar->SetPercent(MaxH > 0.0f ? (Health->GetCurrentHealth() / MaxH) : 1.0f);
		}

		UAshenOath_StatsComponent* Stats = IAshenCharacterInterface::Execute_GetStatsComponent(PlayerPawn);
		if (Stats)
		{
			if (XPBar)
			{
				float Req = Stats->GetXpRequirement();
				XPBar->SetPercent(Req > 0.0f ? (static_cast<float>(Stats->GetExperience()) / Req) : 0.0f);
			}

			if (LevelText)
			{
				LevelText->SetText(FText::FromString(FString::Printf(TEXT("LVL %d"), Stats->GetLevel())));
			}
		}
	}
}
