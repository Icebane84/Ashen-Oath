// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRunicForgeConvergenceSubsystem.h"

UAshenRunicForgeConvergenceSubsystem::UAshenRunicForgeConvergenceSubsystem()
{
	EvolutionState.AscensionTier = EOathbringerAscensionTier::Tier1_DullNightsteel;
	EvolutionState.BaseDamageMultiplier = 1.0f;
	EvolutionState.MaxFlowChargeCap = 100.0f;
	EvolutionState.UnlockedSocketsCount = 0;

	// Initialize 4 Guard Sockets
	GuardSockets.Add(EGuardSigilSocket::VomTagSocket, { EGuardSigilSocket::VomTagSocket, ESigilResonanceEffect::None, false });
	GuardSockets.Add(EGuardSigilSocket::PflugSocket, { EGuardSigilSocket::PflugSocket, ESigilResonanceEffect::None, false });
	GuardSockets.Add(EGuardSigilSocket::OchsSocket, { EGuardSigilSocket::OchsSocket, ESigilResonanceEffect::None, false });
	GuardSockets.Add(EGuardSigilSocket::MordhauSocket, { EGuardSigilSocket::MordhauSocket, ESigilResonanceEffect::None, false });
}

void UAshenRunicForgeConvergenceSubsystem::AscendBladeTier(
	EOathbringerAscensionTier NewTier)
{
	EvolutionState.AscensionTier = NewTier;
	UpdateTierMultipliers();

	OnOathbringerTierAscended.Broadcast(NewTier, EvolutionState);
}

void UAshenRunicForgeConvergenceSubsystem::InscribeSigil(
	EGuardSigilSocket Socket,
	ESigilResonanceEffect Sigil)
{
	if (FGuardSigilSocketData* SocketData = GuardSockets.Find(Socket))
	{
		SocketData->InscribedSigil = Sigil;
		OnGuardSigilInscribed.Broadcast(Socket, Sigil);
		OnRunicSeamGlyphsUpdated.Broadcast(Socket);
	}
}

FFlowResonanceResult UAshenRunicForgeConvergenceSubsystem::TriggerFlowResonance(
	EGuardSigilSocket GuardFrom,
	EGuardSigilSocket GuardTo)
{
	FFlowResonanceResult Result;
	Result.bResonanceTriggered = false;
	Result.HybridDamageMultiplier = 1.0f;

	const ESigilResonanceEffect SigilA = GetInscribedSigil(GuardFrom);
	const ESigilResonanceEffect SigilB = GetInscribedSigil(GuardTo);

	if (SigilA != ESigilResonanceEffect::None && SigilB != ESigilResonanceEffect::None)
	{
		Result.bResonanceTriggered = true;
		Result.HybridDamageMultiplier = 1.40f; // +40% Hybrid Finisher Damage
		Result.FissureRadiusUU = 600.0f;
		Result.VacuumSuctionRadiusUU = 400.0f;
		Result.ResonanceDescription = FText::FromString(TEXT("Flow Resonance: Dual Guard Sigils combined in rhythm cancel finisher!"));

		OnFlowResonanceFinisherExecuted.Broadcast(Result);
	}

	return Result;
}

ESigilResonanceEffect UAshenRunicForgeConvergenceSubsystem::GetInscribedSigil(
	EGuardSigilSocket Socket) const
{
	if (const FGuardSigilSocketData* SocketData = GuardSockets.Find(Socket))
	{
		return SocketData->InscribedSigil;
	}
	return ESigilResonanceEffect::None;
}

void UAshenRunicForgeConvergenceSubsystem::UpdateTierMultipliers()
{
	switch (EvolutionState.AscensionTier)
	{
	case EOathbringerAscensionTier::Tier5_GodslayerApex:
		EvolutionState.BaseDamageMultiplier = 1.50f;
		EvolutionState.MaxFlowChargeCap = 250.0f;
		EvolutionState.UnlockedSocketsCount = 4;
		break;
	case EOathbringerAscensionTier::Tier4_EldrinsCrucible:
		EvolutionState.BaseDamageMultiplier = 1.30f;
		EvolutionState.MaxFlowChargeCap = 200.0f;
		EvolutionState.UnlockedSocketsCount = 4;
		break;
	case EOathbringerAscensionTier::Tier3_SunderedSovereign:
		EvolutionState.BaseDamageMultiplier = 1.20f;
		EvolutionState.MaxFlowChargeCap = 150.0f;
		EvolutionState.UnlockedSocketsCount = 4;
		break;
	case EOathbringerAscensionTier::Tier2_AwakenedFuller:
		EvolutionState.BaseDamageMultiplier = 1.10f;
		EvolutionState.MaxFlowChargeCap = 150.0f;
		EvolutionState.UnlockedSocketsCount = 2;
		break;
	case EOathbringerAscensionTier::Tier1_DullNightsteel:
	default:
		EvolutionState.BaseDamageMultiplier = 1.00f;
		EvolutionState.MaxFlowChargeCap = 100.0f;
		EvolutionState.UnlockedSocketsCount = 0;
		break;
	}

	// Unlock socket accessibility
	for (auto& Pair : GuardSockets)
	{
		Pair.Value.bSocketUnlocked = (EvolutionState.UnlockedSocketsCount >= 4);
	}
}
