// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_ManifestationComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Engine/World.h"
#include "AshenGameSettings.h"
#include "GameFramework/Actor.h"

UAshenOath_ManifestationComponent::UAshenOath_ManifestationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	Timer = 0.0f;
	bActiveInputDelay = false;
	CurrentDistortion = 0.0f;
}

void UAshenOath_ManifestationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Initial delay roll
	Timer = 5.0f;
}

void UAshenOath_ManifestationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float Instability = 0.0f;
	AActor* Owner = GetOwner();
	if (Owner && Owner->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(Owner))
		{
			Instability = 100.0f - Sanity->GetCurrentSanity();
		}
	}

	UpdateManifestation(DeltaTime, Instability);
}

void UAshenOath_ManifestationComponent::UpdateManifestation(float DeltaTime, float Instability)
{
	Timer -= DeltaTime;

	float MinThreshold = 25.0f;
	float MaxDistortion = 0.4f;
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		MinThreshold = Settings->ManifestationMinThreshold;
		MaxDistortion = Settings->ManifestationMaxDistortion;
	}

	// Scale distortion above instability threshold
	float TargetDist = 0.0f;
	if (Instability > MinThreshold)
	{
		TargetDist = FMath::Clamp((Instability - MinThreshold) / FMath::Max(1.0f, 100.0f - MinThreshold), 0.0f, 1.0f) * MaxDistortion;
	}
	CurrentDistortion = FMath::Lerp(CurrentDistortion, TargetDist, DeltaTime * 2.0f);

	if (Timer <= 0.0f)
	{
		TriggerManifestation(Instability);
		Timer = GetInterval(Instability);
	}
}

float UAshenOath_ManifestationComponent::GetInterval(float Instability) const
{
	float MinThreshold = 25.0f;
	float MedThreshold = 50.0f;
	float HighThreshold = 80.0f;
	float MedInterval = 8.0f;
	float HighInterval = 5.0f;
	float CritInterval = 2.5f;

	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		MinThreshold = Settings->ManifestationMinThreshold;
		MedThreshold = Settings->ManifestationMediumThreshold;
		HighThreshold = Settings->ManifestationHighThreshold;
		MedInterval = Settings->ManifestationMediumInterval;
		HighInterval = Settings->ManifestationHighInterval;
		CritInterval = Settings->ManifestationCriticalInterval;
	}

	if (Instability < MinThreshold)
	{
		return 999.0f;
	}
	else if (Instability < MedThreshold)
	{
		return MedInterval;
	}
	else if (Instability < HighThreshold)
	{
		return HighInterval;
	}
	else
	{
		return CritInterval;
	}
}

void UAshenOath_ManifestationComponent::TriggerManifestation(float Instability)
{
	float Roll = FMath::FRand();
	bActiveInputDelay = false;

	FString Type = TEXT("");
	FString Desc = TEXT("");

	float MinThreshold = 25.0f;
	float MedThreshold = 50.0f;
	float HighThreshold = 80.0f;

	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		MinThreshold = Settings->ManifestationMinThreshold;
		MedThreshold = Settings->ManifestationMediumThreshold;
		HighThreshold = Settings->ManifestationHighThreshold;
	}

	if (Instability < MinThreshold)
	{
		return;
	}
	else if (Instability < MedThreshold)
	{
		if (Roll < 0.5f)
		{
			Type = TEXT("WHISPER");
			Desc = TEXT("Whispering static begins to resonate in the player's mind.");
		}
		else
		{
			Type = TEXT("UI_FLICKER");
			Desc = TEXT("Minor interface sync flickering detected.");
		}
	}
	else if (Instability < HighThreshold)
	{
		if (Roll < 0.3f)
		{
			Type = TEXT("FAKE_DAMAGE");
			Desc = TEXT("Ghostly damage metrics generated on player screen.");
		}
		else if (Roll < 0.6f)
		{
			bActiveInputDelay = true;
			Type = TEXT("INPUT_DELAY");
			Desc = TEXT("Instability spikes: input delays active for next phase.");
		}
		else
		{
			Type = TEXT("MISREAD");
			Desc = TEXT("Enemy vectors appear shifted due to cognitive slip.");
		}
	}
	else
	{
		if (Roll < 0.3f)
		{
			Type = TEXT("FORCED_ATTACK");
			Desc = TEXT("Neurolink disruption forces avatar reflex action!");
		}
		else if (Roll < 0.6f)
		{
			Type = TEXT("SHADOW_ECHO");
			Desc = TEXT("Shadow echo strike echoes past position.");
		}
		else
		{
			Type = TEXT("DISTORTION");
			Desc = TEXT("CRITICAL: Full reality distortion triggered.");
		}
	}

	if (!Type.IsEmpty() && GetWorld() && GetWorld()->GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* EventSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventSubsystem->BroadcastManifestationTriggered(Type, Instability, Desc);
		}
	}
}
