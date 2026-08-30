// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGreatswordStanceFlowComponent.h"
#include "Combat/AshenStanceFlowBalanceDataAsset.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenGreatswordStanceFlowComponent::UAshenGreatswordStanceFlowComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStance = EOathbringerMartialStance::VomTag_HighWrath;
	bIsFlowGlintActive = false;
	GlintWindowStartTimestamp = 0.0f;
	BalanceDataAsset = nullptr;
}

void UAshenGreatswordStanceFlowComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenGreatswordStanceFlowComponent::TransitionToGuard(EOathbringerMartialStance NewStance)
{
	if (CurrentStance != NewStance)
	{
		CurrentStance = NewStance;
		FName LineName = FName("NeutralFlick");
		OnStanceChanged.Broadcast(CurrentStance, LineName);
		UE_LOG(LogTemp, Log, TEXT("UAshenGreatswordStanceFlowComponent: Snapped to Guard [%d] via Neutral Input."), (int32)CurrentStance);
	}
}

bool UAshenGreatswordStanceFlowComponent::ExecuteKineticAttackRouting(
	EOathbringerMartialStance TargetStance,
	float BaseStaminaCost,
	float& OutFinalStaminaCost)
{
	FName LineName = FName("StandardCut");
	float DiscountRatio = 0.0f;

	// Evaluate Continuous Kinetic Line Routing
	if (CurrentStance == EOathbringerMartialStance::VomTag_HighWrath && TargetStance == EOathbringerMartialStance::Pflug_LowPlow)
	{
		// Oberhau Follow-Through Cut: Descending overhead cut drives naturally into low hip thrust
		LineName = FName("Oberhau_FollowThrough");
		DiscountRatio = BalanceDataAsset ? BalanceDataAsset->PflugStaminaDiscount : 0.30f;
	}
	else if (CurrentStance == EOathbringerMartialStance::Pflug_LowPlow && TargetStance == EOathbringerMartialStance::Ochs_CrownGuard)
	{
		// Windung / The Winding: Ascending point rotates upward into high eye-level guard
		LineName = FName("Windung_AscendingPoint");
		DiscountRatio = 0.15f;
	}
	else if (CurrentStance == EOathbringerMartialStance::Ochs_CrownGuard && TargetStance == EOathbringerMartialStance::Mordhau_HalfSword)
	{
		// Grip Flip / Inversion: Hands transition to blade flat, turning crossguard forward
		LineName = FName("GripFlip_Inversion");
		DiscountRatio = 0.10f;
	}
	else if (CurrentStance == EOathbringerMartialStance::Mordhau_HalfSword && TargetStance == EOathbringerMartialStance::VomTag_HighWrath)
	{
		// Reset Snap: Blade swings upright and returns over the right shoulder
		LineName = FName("ResetSnap_Overhead");
		DiscountRatio = 0.10f;
	}

	CurrentStance = TargetStance;
	OutFinalStaminaCost = BaseStaminaCost * (1.0f - DiscountRatio);

	OnStanceChanged.Broadcast(CurrentStance, LineName);

	UE_LOG(LogTemp, Log, TEXT("UAshenGreatswordStanceFlowComponent: Kinetic Routing '%s' -> New Guard [%d] (Stamina: %.1f -> %.1f)"),
		*LineName.ToString(), (int32)CurrentStance, BaseStaminaCost, OutFinalStaminaCost);

	return true;
}

void UAshenGreatswordStanceFlowComponent::TriggerFlowGlintWindow(float WindowStartTime)
{
	bIsFlowGlintActive = true;
	GlintWindowStartTimestamp = WindowStartTime;
}

EFlowChainingTimingQuality UAshenGreatswordStanceFlowComponent::EvaluateFlowGlintInput(
	float InputTimestamp,
	float& OutSpeedMultiplier)
{
	const float GlintDuration = BalanceDataAsset ? BalanceDataAsset->FlowGlintDurationSeconds : 0.15f;
	const float SpeedBoost = BalanceDataAsset ? BalanceDataAsset->FlowGlintSpeedMultiplier : 1.25f;

	const float DeltaTime = InputTimestamp - GlintWindowStartTimestamp;

	EFlowChainingTimingQuality Result = EFlowChainingTimingQuality::MissedTiming;
	bool bZeroStamina = false;

	if (bIsFlowGlintActive && DeltaTime >= 0.0f && DeltaTime <= GlintDuration)
	{
		// Perfect Flow Glint Window
		Result = EFlowChainingTimingQuality::FlowGlintClean;
		OutSpeedMultiplier = SpeedBoost;
		bZeroStamina = true;
		bIsFlowGlintActive = false;

		UE_LOG(LogTemp, Log, TEXT("UAshenGreatswordStanceFlowComponent: PERFECT FLOW GLINT HIT! (Speed Boost: %.2fx, Zero Stamina Cancel)"),
			OutSpeedMultiplier);
	}
	else
	{
		// Early or Late Timing
		Result = EFlowChainingTimingQuality::MissedTiming;
		OutSpeedMultiplier = 1.0f;
		bZeroStamina = false;
		bIsFlowGlintActive = false;

		UE_LOG(LogTemp, Verbose, TEXT("UAshenGreatswordStanceFlowComponent: Flow Glint Missed (Delta: %.3fs / Window: %.3fs)."),
			DeltaTime, GlintDuration);
	}

	OnFlowGlintEvaluated.Broadcast(Result, OutSpeedMultiplier, bZeroStamina);
	return Result;
}

bool UAshenGreatswordStanceFlowComponent::EvaluateCompanionPocketResonance(AActor* CompanionActor, FName CompanionID)
{
	if (!CompanionActor) return false;

	const AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return false;

	const float Radius = BalanceDataAsset ? BalanceDataAsset->CompanionPocketRadius : 200.0f;
	const float Distance = FVector::Dist(OwnerActor->GetActorLocation(), CompanionActor->GetActorLocation());

	if (Distance > Radius)
	{
		return false;
	}

	float Multiplier = 1.0f;
	const float TrustReward = BalanceDataAsset ? BalanceDataAsset->DualSigilTrustReward : 0.05f;

	if (CompanionID == FName("Garrett") &&
		(CurrentStance == EOathbringerMartialStance::VomTag_HighWrath || CurrentStance == EOathbringerMartialStance::Mordhau_HalfSword))
	{
		// Garrett Twin Flank Shred
		Multiplier = BalanceDataAsset ? BalanceDataAsset->GarrettFlankMultiplier : 1.80f;
		if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
		{
			FSoulStateVector Delta;
			Delta.Resolve = 0.02f;
			Delta.GarrettTrust = TrustReward;
			Publisher->CommitState(Delta);
		}
		OnDualSigilResonanceTriggered.Broadcast(CompanionID, Multiplier, TrustReward);
		UE_LOG(LogTemp, Log, TEXT("UAshenGreatswordStanceFlowComponent: DUAL-SIGIL TRIGGERED with Garrett -> Twin Flank Shred (%.2fx)!"), Multiplier);
		return true;
	}
	else if (CompanionID == FName("Serafina") &&
		(CurrentStance == EOathbringerMartialStance::Ochs_CrownGuard || CurrentStance == EOathbringerMartialStance::Pflug_LowPlow))
	{
		// Serafina Aegis Harmonic Pulse
		const float StaminaSurge = BalanceDataAsset ? BalanceDataAsset->SerafinaStaminaSurge : 35.0f;
		if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
		{
			FSoulStateVector Delta;
			Delta.Resolve = 0.02f;
			Delta.SerafinaTrust = TrustReward;
			Publisher->CommitState(Delta);
		}
		OnDualSigilResonanceTriggered.Broadcast(CompanionID, StaminaSurge, TrustReward);
		UE_LOG(LogTemp, Log, TEXT("UAshenGreatswordStanceFlowComponent: DUAL-SIGIL TRIGGERED with Serafina -> Aegis Harmonic Pulse (+%.1f Stamina)!"), StaminaSurge);
		return true;
	}

	return false;
}

float UAshenGreatswordStanceFlowComponent::GetActivePoiseMultiplier() const
{
	if (CurrentStance == EOathbringerMartialStance::VomTag_HighWrath)
	{
		return BalanceDataAsset ? BalanceDataAsset->VomTagPoiseMultiplier : 1.40f;
	}
	return 1.0f;
}

float UAshenGreatswordStanceFlowComponent::GetActiveParryWindow() const
{
	float BaseWindow = 0.10f;
	if (CurrentStance == EOathbringerMartialStance::Ochs_CrownGuard)
	{
		BaseWindow += BalanceDataAsset ? BalanceDataAsset->OchsParryWindowBonus : 0.12f;
	}
	return BaseWindow;
}

float UAshenGreatswordStanceFlowComponent::GetActiveArmorPenetration() const
{
	if (CurrentStance == EOathbringerMartialStance::Mordhau_HalfSword)
	{
		return BalanceDataAsset ? BalanceDataAsset->MordhauArmorPenetration : 1.00f;
	}
	return 0.15f; // Baseline edge penetration
}

UAshenSoulPublisher* UAshenGreatswordStanceFlowComponent::GetSoulPublisher() const
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
