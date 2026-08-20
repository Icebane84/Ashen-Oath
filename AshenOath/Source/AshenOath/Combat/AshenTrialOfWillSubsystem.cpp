// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTrialOfWillSubsystem.h"

void UAshenTrialOfWillSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsTrialOfWillActive = false;
	StaggerWindowDurationSeconds = 0.75f;
	TimeDilationScale = 0.05f;
	UE_LOG(LogTemp, Log, TEXT("UAshenTrialOfWillSubsystem: Trial of Will Subsystem initialized (Dilation: %.2f, Window: %.2fs)."),
		TimeDilationScale, StaggerWindowDurationSeconds);
}
void UAshenTrialOfWillSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenTrialOfWillSubsystem::TriggerTrialOfWill(AActor* StaggeredHero)
{
	bIsTrialOfWillActive = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillSubsystem: TRIAL OF WILL TRIGGERED! Global Time Dilation: %.2f for %.2fs!"),
		TimeDilationScale, StaggerWindowDurationSeconds);
}

void UAshenTrialOfWillSubsystem::ResolveTrialOfWill(ETrialOfWillChoice Choice)
{
	bIsTrialOfWillActive = false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillSubsystem: Trial of Will Resolved with Choice: %d! Time Dilation restored."),
		static_cast<int32>(Choice));
}
