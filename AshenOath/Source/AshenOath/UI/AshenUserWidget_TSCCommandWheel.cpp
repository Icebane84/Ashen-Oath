// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 329: Ashen TSC Command Wheel UMG Widget

#include "AshenUserWidget_TSCCommandWheel.h"

void UAshenUserWidget_TSCCommandWheel::DisplayTSCCommandWheel(bool bIsActive, float TimeDilation)
{
	bTSCWheelActive = bIsActive;
	ActiveDilation = TimeDilation;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TSCCommandWheel: TSC Command Wheel Display — Active: %s, Dilation: %.2fx."),
		bIsActive ? TEXT("TRUE") : TEXT("FALSE"), TimeDilation);
}
