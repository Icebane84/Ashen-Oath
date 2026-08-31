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

	CurrentSnapshot.StateVersion = 0;
	CurrentSnapshot.TransactionId = 0;
	CurrentSnapshot.Resolve = 0.5f;
	CurrentSnapshot.Corruption = 0.0f;
	CurrentSnapshot.IntegrationDebt = 0.0f;
	CurrentSnapshot.GameplayEffectiveMass = CalculateGameplayEffectiveMass(0.0f, 0.0f, 0.5f);
	CurrentSnapshot.ActiveStanceTag = FGameplayTag::EmptyTag;
	CurrentSnapshot.SchemaHash = 0x9B4F1103;

	RecalculateSomaticState();
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulPublisher: Initialized SSoT Soul Publisher with authoritative canonical state."));
}

float UAshenSoulPublisher::CalculateGameplayEffectiveMass(float IntegrationDebt, float Corruption, float Resolve)
{
	constexpr float BaseMass = 80.0f;
	constexpr float MinMass = 45.0f;
	constexpr float MaxMass = 120.0f;

	const float ScaledMass = BaseMass * (1.0f + (IntegrationDebt * 0.65f) - (Resolve * 0.35f));
	return FMath::Clamp(ScaledMass, MinMass, MaxMass);
}

void UAshenSoulPublisher::BufferStateDelta(float InResolveDelta, float InCorruptionDelta, float InDebtDelta, float InGarrettDelta, float InSerafinaDelta, FGameplayTag InStanceTag)
{
	ActiveDeltaBuffer.ResolveDelta += InResolveDelta;
	ActiveDeltaBuffer.CorruptionDelta += InCorruptionDelta;
	ActiveDeltaBuffer.IntegrationDebtDelta += InDebtDelta;
	ActiveDeltaBuffer.GarrettRelianceDelta += InGarrettDelta;
	ActiveDeltaBuffer.SerafinaConfidenceDelta += InSerafinaDelta;

	if (InStanceTag.IsValid())
	{
		ActiveDeltaBuffer.NewStanceTag = InStanceTag;
	}

	ActiveDeltaBuffer.bHasPendingMutations = true;
}

bool UAshenSoulPublisher::CommitBufferedTransaction()
{
	// 1. Guard against no-op transactions (StateVersion must not increment on empty buffers)
	if (!ActiveDeltaBuffer.bHasPendingMutations)
	{
		return false;
	}

	// 2. Prevent reentrant mutation commits during observer broadcast
	if (bIsBroadcasting)
	{
		UE_LOG(LogTemp, Error, TEXT("AshenSoulPublisher: Reentrant Commit attempted during broadcast. Transaction rejected."));
		return false;
	}

	// 3. Two-Phase Commit Validation: Ensure relational sink is valid if relational deltas exist
	if (ActiveDeltaBuffer.HasRelationalDelta())
	{
		if (!RelationalBridge.GetInterface() || !RelationalBridge->CanAcceptRelationalDelta())
		{
			UE_LOG(LogTemp, Error, TEXT("AshenSoulPublisher: Relational sink unavailable. Transaction aborted to prevent state divergence."));
			ActiveDeltaBuffer.Reset();
			return false;
		}
	}

	// 4. Construct New State Snapshot
	FAshenStateSnapshot NewSnapshot = CurrentSnapshot;
	NewSnapshot.Resolve = FMath::Clamp(CurrentSnapshot.Resolve + ActiveDeltaBuffer.ResolveDelta, 0.0f, 1.0f);
	NewSnapshot.Corruption = FMath::Clamp(CurrentSnapshot.Corruption + ActiveDeltaBuffer.CorruptionDelta, 0.0f, 1.0f);
	NewSnapshot.IntegrationDebt = FMath::Clamp(CurrentSnapshot.IntegrationDebt + ActiveDeltaBuffer.IntegrationDebtDelta, 0.0f, 1.0f);

	if (ActiveDeltaBuffer.NewStanceTag.IsValid())
	{
		NewSnapshot.ActiveStanceTag = ActiveDeltaBuffer.NewStanceTag;
	}

	NewSnapshot.GameplayEffectiveMass = CalculateGameplayEffectiveMass(NewSnapshot.IntegrationDebt, NewSnapshot.Corruption, NewSnapshot.Resolve);
	NewSnapshot.StateVersion = CurrentSnapshot.StateVersion + 1;
	NewSnapshot.TransactionId = NextTransactionId++;

	// 5. Dispatch Relational Deltas to Narrative Sink
	if (ActiveDeltaBuffer.HasRelationalDelta() && RelationalBridge.GetInterface())
	{
		RelationalBridge->DispatchRelationalDelta(ActiveDeltaBuffer.GarrettRelianceDelta, ActiveDeltaBuffer.SerafinaConfidenceDelta);
	}

	// 6. Synchronize with persistent SoulStateVector
	CurrentSoulState.Resolve = NewSnapshot.Resolve;
	CurrentSoulState.Corruption = NewSnapshot.Corruption;
	CurrentSoulState.IntegrationDebt = NewSnapshot.IntegrationDebt;

	// 7. Commit Canonical State & Reset Buffer
	CurrentSnapshot = NewSnapshot;
	ActiveDeltaBuffer.Reset();

	RecalculateSomaticState();
	PublishStateUpdate();

	// 8. Dispatch Read-Only Broadcast
	BroadcastSnapshot();
	return true;
}

void UAshenSoulPublisher::RegisterConsumer(TScriptInterface<IAshenStateConsumer> Consumer)
{
	if (Consumer.GetInterface() && !RegisteredConsumers.Contains(Consumer))
	{
		RegisteredConsumers.Add(Consumer);
	}
}

void UAshenSoulPublisher::SetRelationalBridge(TScriptInterface<IAshenRelationalBridge> Bridge)
{
	RelationalBridge = Bridge;
}

void UAshenSoulPublisher::BroadcastSnapshot()
{
	bIsBroadcasting = true;

	for (int32 i = RegisteredConsumers.Num() - 1; i >= 0; --i)
	{
		if (RegisteredConsumers[i].GetObject())
		{
			IAshenStateConsumer::Execute_OnStateSnapshotCommitted(RegisteredConsumers[i].GetObject(), CurrentSnapshot);
		}
		else
		{
			RegisteredConsumers.RemoveAt(i);
		}
	}

	bIsBroadcasting = false;
}

void UAshenSoulPublisher::CommitState(const FSoulStateVector& Delta)
{
	CurrentSoulState.Resolve         = FMath::Clamp(CurrentSoulState.Resolve + Delta.Resolve, 0.0f, 1.0f);
	CurrentSoulState.Corruption      = FMath::Clamp(CurrentSoulState.Corruption + Delta.Corruption, 0.0f, 1.0f);
	CurrentSoulState.IntegrationDebt = FMath::Clamp(CurrentSoulState.IntegrationDebt + Delta.IntegrationDebt, 0.0f, 1.0f);
	CurrentSoulState.Isolation       = FMath::Clamp(CurrentSoulState.Isolation + Delta.Isolation, 0.0f, 1.0f);
	CurrentSoulState.GarrettTrust    = FMath::Clamp(CurrentSoulState.GarrettTrust + Delta.GarrettTrust, 0.0f, 1.0f);
	CurrentSoulState.SerafinaTrust   = FMath::Clamp(CurrentSoulState.SerafinaTrust + Delta.SerafinaTrust, 0.0f, 1.0f);

	CurrentSnapshot.Resolve = CurrentSoulState.Resolve;
	CurrentSnapshot.Corruption = CurrentSoulState.Corruption;
	CurrentSnapshot.IntegrationDebt = CurrentSoulState.IntegrationDebt;
	CurrentSnapshot.GameplayEffectiveMass = CalculateGameplayEffectiveMass(CurrentSoulState.IntegrationDebt, CurrentSoulState.Corruption, CurrentSoulState.Resolve);
	CurrentSnapshot.StateVersion++;
	CurrentSnapshot.TransactionId = NextTransactionId++;

	RecalculateSomaticState();
	PublishStateUpdate();
	BroadcastSnapshot();
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

	CurrentSnapshot.Resolve = CurrentSoulState.Resolve;
	CurrentSnapshot.Corruption = CurrentSoulState.Corruption;
	CurrentSnapshot.IntegrationDebt = CurrentSoulState.IntegrationDebt;
	CurrentSnapshot.GameplayEffectiveMass = CalculateGameplayEffectiveMass(CurrentSoulState.IntegrationDebt, CurrentSoulState.Corruption, CurrentSoulState.Resolve);
	CurrentSnapshot.StateVersion++;
	CurrentSnapshot.TransactionId = NextTransactionId++;

	RecalculateSomaticState();
	PublishStateUpdate();
	BroadcastSnapshot();
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
