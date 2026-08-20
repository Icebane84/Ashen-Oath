// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticTraumaAudioComponent.h"

UAshenDiegeticTraumaAudioComponent::UAshenDiegeticTraumaAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticTraumaAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticTraumaAudioComponent::UpdateDebtAudioState(EIntegrationDebtStage Stage)
{
	if (Stage == EIntegrationDebtStage::MemoryBleed)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTraumaAudioComponent: Playing Whispering Winds Traversal Echoes."));
	}
	else if (Stage == EIntegrationDebtStage::RuntimeNoise)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticTraumaAudioComponent: Playing Heartbeat Friction & Sound Muffling."));
	}
}
