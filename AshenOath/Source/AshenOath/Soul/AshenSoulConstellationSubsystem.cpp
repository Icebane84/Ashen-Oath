// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenSoulConstellationSubsystem.h"

void UAshenSoulConstellationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: ENGINE-SPEC-001 Sovereign Kernel initialized. FSoulStateVector ready for imprint ingestion."));
}

void UAshenSoulConstellationSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenSoulConstellationSubsystem::InvokeIntegration(bool bForcedCollapse)
{
	CompileIdentity(bForcedCollapse);
}

void UAshenSoulConstellationSubsystem::FinalizeIntegration(EInterpretiveLens Lens)
{
	CurrentStateVector.PrimaryLens = Lens;
	KernelIdentityState.IntegrationDebt = 0.0f;
	CurrentStateVector.IntegrationDebt = 0.0f;
	CompileIdentity(false);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: FinalizeIntegration completed for lens %d"), (int32)Lens);
}

void UAshenSoulConstellationSubsystem::ApplyDespairOnDeath(float Amount)
{
	DespairLevel = FMath::Clamp(DespairLevel + Amount, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: Despair increased by %f to %f"), Amount, DespairLevel);
}

void UAshenSoulConstellationSubsystem::LoadSavedState(const FSoulStateVector& SavedVector, float SavedDespair)
{
	CurrentStateVector = SavedVector;
	DespairLevel = SavedDespair;
	KernelIdentityState.IntegrationDebt = SavedVector.IntegrationDebt;
	KernelIdentityState.ResolveScore = SavedVector.Resolve;
	PublishStateVector();
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: Loaded saved state — Debt=%f Despair=%f"), SavedVector.IntegrationDebt, SavedDespair);
}

void UAshenSoulConstellationSubsystem::CompileIdentity(bool bForcedCollapse)
{
	if (bForcedCollapse || KernelIdentityState.IntegrationDebt >= 1.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSoulConstellationSubsystem: FORCED COLLAPSE — InvokeIntegration triggered at IntegrationDebt=%f"), KernelIdentityState.IntegrationDebt);
		KernelIdentityState.IntegrationDebt = FMath::Clamp(KernelIdentityState.IntegrationDebt, 0.0f, 1.0f);
		CurrentStateVector.IntegrationDebt = KernelIdentityState.IntegrationDebt;
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::ForcedCollapse;
	}

	EvaluateBehavioralProfile();
	EvaluateDebtStage();
	PublishStateVector();

	if (OnIdentityCompilationComplete.IsBound())
	{
		OnIdentityCompilationComplete.Broadcast();
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: Identity compiled. Stance=%d Empathic=%d Tactical=%d Debt=%f Stage=%d"),
		(int32)KernelIdentityState.CompiledProfile.StanceProfile,
		(int32)KernelIdentityState.CompiledProfile.EmpathicProfile,
		(int32)KernelIdentityState.CompiledProfile.TacticalProfile,
		KernelIdentityState.IntegrationDebt,
		(int32)KernelIdentityState.DebtStage);
}

void UAshenSoulConstellationSubsystem::PublishStateVector()
{
	if (OnStateVectorInvalidated.IsBound())
	{
		OnStateVectorInvalidated.Broadcast(CurrentStateVector);
	}
	InvalidateSubsystems();
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulConstellationSubsystem: PublishStateVector broadcast fired to all downstream subscribers."));
}

EAshenIntegrationDebtStage UAshenSoulConstellationSubsystem::GetDebtStage() const
{
	return KernelIdentityState.DebtStage;
}

void UAshenSoulConstellationSubsystem::ApplyRawWeightDeltas(float StanceDelta, float EmpathicDelta, float TacticalDelta, float DebtDelta)
{
	KernelIdentityState.StanceWeight   = FMath::Clamp(KernelIdentityState.StanceWeight   + StanceDelta,   0.0f, 1.0f);
	KernelIdentityState.EmpathicWeight = FMath::Clamp(KernelIdentityState.EmpathicWeight + EmpathicDelta, 0.0f, 1.0f);
	KernelIdentityState.TacticalWeight = FMath::Clamp(KernelIdentityState.TacticalWeight + TacticalDelta, 0.0f, 1.0f);
	KernelIdentityState.IntegrationDebt = FMath::Clamp(KernelIdentityState.IntegrationDebt + DebtDelta,   0.0f, 1.5f);

	CurrentStateVector.IntegrationDebt = KernelIdentityState.IntegrationDebt;
	CurrentStateVector.Resolve         = KernelIdentityState.ResolveScore;
	UE_LOG(LogTemp, Verbose, TEXT("UAshenSoulConstellationSubsystem: ApplyRawWeightDeltas — Debt now %f"), KernelIdentityState.IntegrationDebt);
}

void UAshenSoulConstellationSubsystem::EvaluateBehavioralProfile()
{
	// Stance profile evaluation
	if (KernelIdentityState.StanceWeight >= 0.70f)
	{
		KernelIdentityState.CompiledProfile.StanceProfile = EAshenStanceProfile::Resolved_Protector;
		ActiveProfile.Stance = EStanceProfile::Upright_Grounded;
	}
	else if (KernelIdentityState.StanceWeight >= 0.50f)
	{
		KernelIdentityState.CompiledProfile.StanceProfile = EAshenStanceProfile::Reckless_Avenger;
		ActiveProfile.Stance = EStanceProfile::Balanced_Steady;
	}
	else if (KernelIdentityState.StanceWeight >= 0.30f)
	{
		KernelIdentityState.CompiledProfile.StanceProfile = EAshenStanceProfile::Cynical_Isolated;
		ActiveProfile.Stance = EStanceProfile::Hunched_Guarded;
	}
	else
	{
		KernelIdentityState.CompiledProfile.StanceProfile = EAshenStanceProfile::Fractured_Reactive;
		ActiveProfile.Stance = EStanceProfile::Hunched_Guarded;
	}

	// Empathic profile evaluation
	if (KernelIdentityState.EmpathicWeight >= 0.70f)
	{
		KernelIdentityState.CompiledProfile.EmpathicProfile = EAshenEmpathicProfile::Open_Compassionate;
		ActiveProfile.Empathic = EEmpathicProfile::Radiant_Shield;
	}
	else if (KernelIdentityState.EmpathicWeight >= 0.50f)
	{
		KernelIdentityState.CompiledProfile.EmpathicProfile = EAshenEmpathicProfile::Guarded_Transactional;
		ActiveProfile.Empathic = EEmpathicProfile::Resonant_Attuned;
	}
	else if (KernelIdentityState.EmpathicWeight >= 0.30f)
	{
		KernelIdentityState.CompiledProfile.EmpathicProfile = EAshenEmpathicProfile::Burned_Out;
		ActiveProfile.Empathic = EEmpathicProfile::Burned_Out;
	}
	else
	{
		KernelIdentityState.CompiledProfile.EmpathicProfile = EAshenEmpathicProfile::Dissociated_Hollow;
		ActiveProfile.Empathic = EEmpathicProfile::Burned_Out;
	}

	// Tactical profile evaluation
	if (KernelIdentityState.TacticalWeight >= 0.70f)
	{
		KernelIdentityState.CompiledProfile.TacticalProfile = EAshenTacticalProfile::Methodical_Calculated;
		ActiveProfile.Tactical = ETacticalProfile::Unshakeable_Anchor;
	}
	else if (KernelIdentityState.TacticalWeight >= 0.50f)
	{
		KernelIdentityState.CompiledProfile.TacticalProfile = EAshenTacticalProfile::Aggressive_Volatile;
		ActiveProfile.Tactical = ETacticalProfile::Calculated_Pragmatic;
	}
	else if (KernelIdentityState.TacticalWeight >= 0.30f)
	{
		KernelIdentityState.CompiledProfile.TacticalProfile = EAshenTacticalProfile::Evasive_Cautious;
		ActiveProfile.Tactical = ETacticalProfile::Cynical_Isolated;
	}
	else
	{
		KernelIdentityState.CompiledProfile.TacticalProfile = EAshenTacticalProfile::Paralyzed_Overwhelmed;
		ActiveProfile.Tactical = ETacticalProfile::Cynical_Isolated;
	}
}

void UAshenSoulConstellationSubsystem::EvaluateDebtStage()
{
	const float Debt = KernelIdentityState.IntegrationDebt;
	EAshenIntegrationDebtStage PrevStage = KernelIdentityState.DebtStage;

	if (Debt >= 1.0f)
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::ForcedCollapse;
	else if (Debt >= 0.75f)
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::RuntimeNoise;
	else if (Debt >= 0.50f)
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::MemoryBleed;
	else if (Debt >= 0.25f)
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::LatentPressure;
	else
		KernelIdentityState.DebtStage = EAshenIntegrationDebtStage::Stable;

	if (KernelIdentityState.DebtStage != PrevStage && OnIntegrationDebtStageChanged.IsBound())
	{
		OnIntegrationDebtStageChanged.Broadcast(KernelIdentityState.DebtStage);
	}
}

void UAshenSoulConstellationSubsystem::InvalidateSubsystems()
{
	UE_LOG(LogTemp, Verbose, TEXT("UAshenSoulConstellationSubsystem: InvalidateSubsystems pulse fired."));
}
