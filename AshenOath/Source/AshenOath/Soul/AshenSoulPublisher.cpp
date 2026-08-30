// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulDerivationSubsystem.h"
#include "Engine/GameInstance.h"

void UAshenSoulPublisher::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Baseline state initialization
	CurrentSoulState.Resolve = 0.50f;
	CurrentSoulState.Corruption = 0.0f;
	CurrentSoulState.IntegrationDebt = 0.0f;
	CurrentSoulState.Isolation = 0.0f;
	CurrentSoulState.GarrettTrust = 0.50f;
	CurrentSoulState.SerafinaTrust = 0.50f;
	CurrentSoulState.PrimaryLens = EInterpretiveLens::Accountability;

	RecalculateSomaticState();
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulPublisher: Initialized SSoT Soul Publisher with authoritative canonical state."));
}

void UAshenSoulPublisher::CommitState(const FSoulStateVector& Delta)
{
	CurrentSoulState.Resolve         = FMath::Clamp(CurrentSoulState.Resolve + Delta.Resolve, 0.0f, 1.0f);
	CurrentSoulState.Corruption      = FMath::Clamp(CurrentSoulState.Corruption + Delta.Corruption, 0.0f, 1.0f);
	CurrentSoulState.IntegrationDebt = FMath::Clamp(CurrentSoulState.IntegrationDebt + Delta.IntegrationDebt, 0.0f, 1.0f);
	CurrentSoulState.Isolation       = FMath::Clamp(CurrentSoulState.Isolation + Delta.Isolation, 0.0f, 1.0f);
	CurrentSoulState.GarrettTrust    = FMath::Clamp(CurrentSoulState.GarrettTrust + Delta.GarrettTrust, 0.0f, 1.0f);
	CurrentSoulState.SerafinaTrust   = FMath::Clamp(CurrentSoulState.SerafinaTrust + Delta.SerafinaTrust, 0.0f, 1.0f);

	RecalculateSomaticState();
	PublishStateUpdate();
}

void UAshenSoulPublisher::CommitStateDirect(const FSoulStateVector& NewState)
{
	CurrentSoulState.Resolve         = FMath::Clamp(NewState.Resolve, 0.0f, 1.0f);
	CurrentSoulState.Corruption      = FMath::Clamp(NewState.Corruption, 0.0f, 1.0f);
	CurrentSoulState.IntegrationDebt = FMath::Clamp(NewState.IntegrationDebt, 0.0f, 1.0f);
	CurrentSoulState.Isolation       = FMath::Clamp(NewState.Isolation, 0.0f, 1.0f);
	CurrentSoulState.GarrettTrust    = FMath::Clamp(NewState.GarrettTrust, 0.0f, 1.0f);
	CurrentSoulState.SerafinaTrust   = FMath::Clamp(NewState.SerafinaTrust, 0.0f, 1.0f);
	CurrentSoulState.PrimaryLens     = NewState.PrimaryLens;

	RecalculateSomaticState();
	PublishStateUpdate();
}

void UAshenSoulPublisher::SetRelationalMatrix(const FRelationalMatrix_V2& NewMatrix)
{
	CurrentRelationalMatrix = NewMatrix;
	CurrentSoulState.GarrettTrust = FMath::Clamp(NewMatrix.GarrettProfile.TacticalConfidence, 0.0f, 1.0f);
	CurrentSoulState.SerafinaTrust = FMath::Clamp(NewMatrix.SerafinaProfile.TacticalConfidence, 0.0f, 1.0f);

	if (OnRelationalMatrixUpdated.IsBound())
	{
		OnRelationalMatrixUpdated.Broadcast(CurrentRelationalMatrix);
	}

	RecalculateSomaticState();
	PublishStateUpdate();
}

void UAshenSoulPublisher::RecalculateSomaticState()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSoulDerivationSubsystem* DerivationSubsystem = GI->GetSubsystem<UAshenSoulDerivationSubsystem>())
		{
			CurrentSomaticState = DerivationSubsystem->EvaluateSomaticState(CurrentSoulState);
			return;
		}
	}

	// Fallback in-situ evaluation if subsystem unavailable during isolation tests
	const float Dysregulation = CurrentSoulState.Isolation;
	const float Friction = (0.25f * CurrentSoulState.IntegrationDebt) +
	                       (0.25f * Dysregulation) +
	                       (0.15f * (1.0f - CurrentSoulState.Resolve));

	const float TrioResonance = (CurrentSoulState.GarrettTrust + CurrentSoulState.SerafinaTrust) * 0.5f;

	CurrentSomaticState.InternalFriction = FMath::Clamp(Friction, 0.0f, 1.0f);
	CurrentSomaticState.ParasitePressure = FMath::Clamp((0.40f * CurrentSoulState.Corruption) + (0.35f * Friction) + (0.25f * (1.0f - CurrentSoulState.Resolve)), 0.0f, 1.0f);
	CurrentSomaticState.RelationalFlow   = FMath::Clamp((0.45f * TrioResonance) + 0.25f, 0.0f, 1.0f);
	CurrentSomaticState.IsolationPressure = FMath::Clamp(0.55f * (1.0f - CurrentSomaticState.RelationalFlow), 0.0f, 1.0f);
}

void UAshenSoulPublisher::PublishStateUpdate()
{
	if (OnSoulStateCommitted.IsBound())
	{
		OnSoulStateCommitted.Broadcast(CurrentSoulState, CurrentSomaticState);
	}
}
