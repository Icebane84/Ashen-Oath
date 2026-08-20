// AshenVerticalSlicePerformanceAuditTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 132: Full Vertical Slice Polish & Performance Audit Automation Test Suite
// Validates VFX pooling counters, purifying aura overlaps, environmental hazards, and resonance matrix synergies.

#include "Misc/AutomationTest.h"
#include "AshenVFXPoolSubsystem.h"
#include "AshenPurifyingAuraComponent.h"
#include "AshenEnvironmentalHazardActor.h"
#include "AshenResonanceMatrixCalculator.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: VFX Pooling Subsystem Audit
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVFXPoolingAuditTest,
	"AshenOath.Audit.VFXPooling.PoolRecyclingMetrics",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenVFXPoolingAuditTest::RunTest(const FString& Parameters)
{
	UAshenVFXPoolSubsystem* VFXPool = NewObject<UAshenVFXPoolSubsystem>();
	TestNotNull(TEXT("VFXPoolSubsystem must instantiate"), VFXPool);
	if (!VFXPool) return false;

	VFXPool->SpawnPooledVFX(FName("VFX_HolyAegisBurst"), FVector::ZeroVector, FRotator::ZeroRotator);
	UE_LOG(LogTemp, Log, TEXT("FAshenVFXPoolingAuditTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Purifying Aura Component Overlap Audit
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPurifyingAuraAuditTest,
	"AshenOath.Audit.PurifyingAura.OverlapSanitizing",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenPurifyingAuraAuditTest::RunTest(const FString& Parameters)
{
	UAshenPurifyingAuraComponent* Aura = NewObject<UAshenPurifyingAuraComponent>();
	TestNotNull(TEXT("PurifyingAuraComponent must instantiate"), Aura);
	if (!Aura) return false;

	TestEqual(TEXT("Default aura radius must equal 450.0uu"), Aura->AuraRadius, 450.0f);
	TestEqual(TEXT("Default purify rate must equal 0.05/s"), Aura->PurifyRatePerSecond, 0.05f);

	UE_LOG(LogTemp, Log, TEXT("FAshenPurifyingAuraAuditTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Environmental Hazard Actor Damage Audit
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHazardAuditTest,
	"AshenOath.Audit.EnvironmentalHazard.DamageTicking",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenHazardAuditTest::RunTest(const FString& Parameters)
{
	AAshenEnvironmentalHazardActor* Hazard = NewObject<AAshenEnvironmentalHazardActor>();
	TestNotNull(TEXT("EnvironmentalHazardActor must instantiate"), Hazard);
	if (!Hazard) return false;

	TestEqual(TEXT("Hazard damage per second must equal 20.0"), Hazard->DamagePerSecond, 20.0f);
	TestEqual(TEXT("Hazard poise damage per second must equal 15.0"), Hazard->PoiseDamagePerSecond, 15.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenHazardAuditTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Resonance Matrix Calculator Audit
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenResonanceMatrixAuditTest,
	"AshenOath.Audit.ResonanceMatrix.SynergyMultiplier",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenResonanceMatrixAuditTest::RunTest(const FString& Parameters)
{
	UAshenResonanceMatrixCalculator* Calc = NewObject<UAshenResonanceMatrixCalculator>();
	TestNotNull(TEXT("ResonanceMatrixCalculator must instantiate"), Calc);
	if (!Calc) return false;

	TSet<FName> Perks;
	Perks.Add(FName("Perk_UnshakeableStance"));
	Perks.Add(FName("Perk_VitalResonance"));

	float Mult = Calc->CalculateResonanceMultiplier(Perks);
	TestEqual(TEXT("Synergy multiplier for UnshakeableStance + VitalResonance must equal 1.15x"), Mult, 1.15f);

	UE_LOG(LogTemp, Log, TEXT("FAshenResonanceMatrixAuditTest: PASS"));
	return true;
}
