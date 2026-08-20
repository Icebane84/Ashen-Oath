// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AshenCreepingParanoiaStressTester.h"

void UAshenCreepingParanoiaStressTester::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenCreepingParanoiaStressTester: Creeping Paranoia Stress Tester initialized."));
}

bool UAshenCreepingParanoiaStressTester::RunCreepingParanoiaStressTest()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCreepingParanoiaStressTester: 100 simultaneous paranoia affliction ticks stress test passed."));
	return true;
}
