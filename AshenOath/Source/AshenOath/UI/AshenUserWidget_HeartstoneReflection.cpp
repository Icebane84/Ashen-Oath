// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 307: Ashen Heartstone Reflection UMG Widget (UMB-SYS-005)

#include "AshenUserWidget_HeartstoneReflection.h"

void UAshenUserWidget_HeartstoneReflection::DisplayTrueSoulReflection(const FAshenSoulStateVector& TrueSoulVector)
{
	DisplayedSoulVector = TrueSoulVector;
	bReflectionActive = true;

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_HeartstoneReflection: TRUE SOUL VECTOR REFLECTION DISPLAYED — IntegrationDebt: %.1f, Corruption: %.1f."),
		TrueSoulVector.IntegrationDebt, TrueSoulVector.CorruptionLevel);
}

void UAshenUserWidget_HeartstoneReflection::CloseReflectionScreen()
{
	bReflectionActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_HeartstoneReflection: Reflection screen closed. Returning to Diegetic World."));
}


