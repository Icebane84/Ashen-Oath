// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenParchmentInspectionGASAbility.h"

UAshenParchmentInspectionGASAbility::UAshenParchmentInspectionGASAbility()
{
}

bool UAshenParchmentInspectionGASAbility::InspectParchmentPage(AActor* InstigatorActor, FName BestiaryID)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenParchmentInspectionGASAbility: Inspecting Living Journal Page for '%s'."), *BestiaryID.ToString());
	return true;
}
