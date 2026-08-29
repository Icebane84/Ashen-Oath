// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Combat/AshenSeverancePlaneEvaluator.h"
#include "Combat/AshenAdrenalineSurgeEvaluator.h"
#include "Combat/AshenSeveranceBalanceDataAsset.h"
#include "Combat/AshenSeveranceTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSeveranceConvergenceIntegrationTest,
	"AshenOath.Convergence.Severance.DismembermentAndAdrenaline",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSeveranceConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & EVALUATORS
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("SeveranceTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UAshenSeverancePlaneEvaluator* PlaneEvaluator = NewObject<UAshenSeverancePlaneEvaluator>(World);
	UAshenAdrenalineSurgeEvaluator* AdrenalineEvaluator = NewObject<UAshenAdrenalineSurgeEvaluator>(World);

	TestNotNull(TEXT("PlaneEvaluator instantiated"), PlaneEvaluator);
	TestNotNull(TEXT("AdrenalineEvaluator instantiated"), AdrenalineEvaluator);

	// -----------------------------------------------------------------------------------
	// 2. TEST DECAPITATION & BISECTION SLICE PLANES & IMPULSES
	// -----------------------------------------------------------------------------------
	if (PlaneEvaluator)
	{
		// Decapitation (Head)
		const FSeveranceSlicePlaneData HeadSlice = PlaneEvaluator->EvaluateSlicePlane(FVector(0, 0, 160), FVector(1, 0, 0), ESeveranceBoneTarget::Head);
		TestNearlyEqual(TEXT("Head slice plane normal Z is 1.0"), static_cast<float>(HeadSlice.PlaneNormal.Z), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Head slice impulse strength is 750.0uu"), HeadSlice.ImpulseStrength, 750.0f, 0.1f);

		// Total Bisection (TorsoWaist)
		const FSeveranceSlicePlaneData TorsoSlice = PlaneEvaluator->EvaluateSlicePlane(FVector(0, 0, 100), FVector(1, 0, 0), ESeveranceBoneTarget::TorsoWaist);
		TestNearlyEqual(TEXT("Torso slice impulse strength is 1100.0uu"), TorsoSlice.ImpulseStrength, 1100.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SOMATIC ADRENALINE GAINS ACROSS SEVERITY TIERS
	// -----------------------------------------------------------------------------------
	if (AdrenalineEvaluator)
	{
		const float DecapAdrenaline = AdrenalineEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::Decapitation);
		const float BisectionAdrenaline = AdrenalineEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::TotalBisection);
		const float LimbAdrenaline = AdrenalineEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::MajorLimb);

		TestNearlyEqual(TEXT("Decapitation awards 35.0 Adrenaline"), DecapAdrenaline, 35.0f, 0.1f);
		TestNearlyEqual(TEXT("Total Bisection awards 40.0 Adrenaline"), BisectionAdrenaline, 40.0f, 0.1f);
		TestNearlyEqual(TEXT("Major Limb amputation awards 25.0 Adrenaline"), LimbAdrenaline, 25.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST STAMINA REFILL SCALING
	// -----------------------------------------------------------------------------------
	if (AdrenalineEvaluator)
	{
		// 50 Adrenaline * 0.50 = 25 Stamina
		const float Refill50 = AdrenalineEvaluator->EvaluateStaminaRefill(50.0f);
		TestNearlyEqual(TEXT("50.0 Adrenaline refills +25.0 Stamina"), Refill50, 25.0f, 0.1f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	if (PlaneEvaluator && AdrenalineEvaluator)
	{
		UAshenSeveranceBalanceDataAsset* BalanceAsset = NewObject<UAshenSeveranceBalanceDataAsset>(World);
		BalanceAsset->ImpulseBalancing.DecapitationImpulse = 1500.0f;
		BalanceAsset->AdrenalineBalancing.DecapitationAdrenaline = 55.0f;

		PlaneEvaluator->BalanceDataAsset = BalanceAsset;
		AdrenalineEvaluator->BalanceDataAsset = BalanceAsset;

		const FSeveranceSlicePlaneData CustomSlice = PlaneEvaluator->EvaluateSlicePlane(FVector(0, 0, 160), FVector(1, 0, 0), ESeveranceBoneTarget::Head);
		const float CustomAdrenaline = AdrenalineEvaluator->EvaluateAdrenalineGain(ESeveranceSeverityTier::Decapitation);

		TestNearlyEqual(TEXT("DataAsset live override sets Decapitation impulse to 1500.0uu"), CustomSlice.ImpulseStrength, 1500.0f, 0.1f);
		TestNearlyEqual(TEXT("DataAsset live override sets Decapitation adrenaline to 55.0"), CustomAdrenaline, 55.0f, 0.1f);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
