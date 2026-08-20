// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatSliceStateAdapterComponent.h"
#include "Companions/AshenCompanionSliceStateAdapterComponent.h"
#include "World/AshenWorldSliceStateAdapterComponent.h"
#include "World/AshenAudioSliceStateAdapterComponent.h"
#include "World/AshenSomaticSliceStateAdapterComponent.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenModularVerticalSliceTest,
	"AshenOath.Milestone715.ModularVerticalSlice.Unification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenModularVerticalSliceTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.5f;
	State.Corruption = 0.8f;
	State.Isolation = 0.6f;
	State.GarrettTrust = 0.4f;

	// 1. Test Combat Slice Adapter
	UAshenCombatSliceStateAdapterComponent* CombatSlice = NewObject<UAshenCombatSliceStateAdapterComponent>();
	CombatSlice->OnSoulStateInvalidated(State);

	// 2. Test Companion Slice Adapter
	UAshenCompanionSliceStateAdapterComponent* CompanionSlice = NewObject<UAshenCompanionSliceStateAdapterComponent>();
	CompanionSlice->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Garrett formation distance scaled for high isolation"), CompanionSlice->GetGarrettFormationDistance() > 1.0f);

	// 3. Test World Slice Adapter
	UAshenWorldSliceStateAdapterComponent* WorldSlice = NewObject<UAshenWorldSliceStateAdapterComponent>();
	WorldSlice->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Weather tension scaled for high corruption"), WorldSlice->GetWeatherTension() > 0.5f);

	// 4. Test Audio Slice Adapter
	UAshenAudioSliceStateAdapterComponent* AudioSlice = NewObject<UAshenAudioSliceStateAdapterComponent>();
	AudioSlice->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Whisper volume matches corruption"), AudioSlice->GetWhisperVolumeMultiplier(), 0.8f);

	// 5. Test Somatic Slice Adapter
	UAshenSomaticSliceStateAdapterComponent* SomaticSlice = NewObject<UAshenSomaticSliceStateAdapterComponent>();
	SomaticSlice->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Eye emissive scales 5x corruption"), SomaticSlice->GetEyeEmissiveIntensity(), 4.0f);

	return true;
}
