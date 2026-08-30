// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticCompanionTrustAudioComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenDiegeticCompanionTrustAudioComponent::UAshenDiegeticCompanionTrustAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsHarmonyActive = false;
}

void UAshenDiegeticCompanionTrustAudioComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		Publisher->OnRelationalMatrixUpdated.AddDynamic(this, &UAshenDiegeticCompanionTrustAudioComponent::HandleRelationalMatrixUpdated);
		HandleRelationalMatrixUpdated(Publisher->GetRelationalMatrix());
	}
}

void UAshenDiegeticCompanionTrustAudioComponent::HandleRelationalMatrixUpdated(const FRelationalMatrix_V2& NewMatrix)
{
	if (NewMatrix.TrioResonance >= 0.75f)
	{
		TriggerResonanceHarmonyChord();
	}
	else if (NewMatrix.TrioResonance < 0.35f)
	{
		TriggerDivergenceDiscordDrone(0.35f - NewMatrix.TrioResonance);
	}
	else
	{
		bIsHarmonyActive = false;
	}
}

void UAshenDiegeticCompanionTrustAudioComponent::TriggerResonanceHarmonyChord()
{
	bIsHarmonyActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCompanionTrustAudioComponent: Resonance harmony chord triggered (Solfeggio Triad active)."));
}

void UAshenDiegeticCompanionTrustAudioComponent::TriggerDivergenceDiscordDrone(float TrustDivergenceDelta)
{
	bIsHarmonyActive = false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticCompanionTrustAudioComponent: Divergence discord drone triggered (Resonance deficit=%f)."), TrustDivergenceDelta);
}

UAshenSoulPublisher* UAshenDiegeticCompanionTrustAudioComponent::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
