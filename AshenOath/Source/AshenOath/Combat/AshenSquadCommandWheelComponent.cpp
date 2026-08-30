// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSquadCommandWheelComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenSquadCommandWheelComponent::UAshenSquadCommandWheelComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BulletTimeDilation = 0.20f;
	bIsWheelOpen = false;
}

void UAshenSquadCommandWheelComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSquadCommandWheelComponent::OpenCommandWheel()
{
	if (!bIsWheelOpen)
	{
		bIsWheelOpen = true;
		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::SetGlobalTimeDilation(World, BulletTimeDilation);
		}
		OnCommandWheelStateChanged.Broadcast(true);
		UE_LOG(LogTemp, Log, TEXT("AshenSquadCommandWheel: Opened wheel -- 0.20x bullet-time engaged."));
	}
}

void UAshenSquadCommandWheelComponent::CloseCommandWheel()
{
	if (bIsWheelOpen)
	{
		bIsWheelOpen = false;
		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::SetGlobalTimeDilation(World, 1.0f);
		}
		OnCommandWheelStateChanged.Broadcast(false);
		UE_LOG(LogTemp, Log, TEXT("AshenSquadCommandWheel: Closed wheel -- 1.0x time dilation restored."));
	}
}

bool UAshenSquadCommandWheelComponent::ExecuteSquadCommand(EAshenSquadCommand DesiredCommand, AActor* TargetActor)
{
	// Always close wheel upon command selection
	CloseCommandWheel();

	UAshenSoulPublisher* Publisher = GetSoulPublisher();
	FRelationalMatrix_V2 RelMatrix;
	if (Publisher)
	{
		RelMatrix = Publisher->GetRelationalMatrix();
	}

	EAshenSquadCommand ExecutedCommand = DesiredCommand;
	bool bWasFallback = false;

	switch (DesiredCommand)
	{
	case EAshenSquadCommand::Garrett_PauldronVault:
		// If Garrett's Somatic Dread is high (>= 0.60), he refuses close vault and defaults to ranged Caltrop Snare
		if (RelMatrix.GarrettProfile.SomaticDread >= 0.60f)
		{
			ExecutedCommand = EAshenSquadCommand::Garrett_CaltropSnare;
			bWasFallback = true;
			UE_LOG(LogTemp, Warning, TEXT("AshenSquadCommandWheel: Garrett SomaticDread (%f >= 0.60) forced fallback to Caltrop Snare!"),
				RelMatrix.GarrettProfile.SomaticDread);
		}
		break;

	case EAshenSquadCommand::Serafina_ConduitBurst:
		// If Serafina's Transference Burnout is high (>= 0.70), she locks offensive burst and executes Aegis Barrier
		if (RelMatrix.SerafinaProfile.TransferenceBurnout >= 0.70f)
		{
			ExecutedCommand = EAshenSquadCommand::Serafina_AegisBarrier;
			bWasFallback = true;

			// Add canonical dysregulation penalty for burned out barrier
			if (Publisher)
			{
				FSoulStateVector Delta;
				Delta.Resolve = 0.0f;
				Delta.Corruption = 0.0f;
				Delta.IntegrationDebt = 0.0f;
				Delta.Isolation = 0.10f; // Canonical Dysregulation (N)
				Delta.GarrettTrust = 0.0f;
				Delta.SerafinaTrust = 0.0f;
				Publisher->CommitState(Delta);
			}

			UE_LOG(LogTemp, Warning, TEXT("AshenSquadCommandWheel: Serafina Burnout (%f >= 0.70) locked offensive burst, executed Aegis Barrier!"),
				RelMatrix.SerafinaProfile.TransferenceBurnout);
		}
		break;

	default:
		break;
	}

	OnSquadOrderDispatched.Broadcast(ExecutedCommand, bWasFallback);
	OnSquadOrderDispatchedNative.Broadcast(ExecutedCommand, bWasFallback);
	return true;
}

UAshenSoulPublisher* UAshenSquadCommandWheelComponent::GetSoulPublisher() const
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
