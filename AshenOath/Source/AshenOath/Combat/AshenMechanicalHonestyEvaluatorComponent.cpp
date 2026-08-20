// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMechanicalHonestyEvaluatorComponent.h"

UAshenMechanicalHonestyEvaluatorComponent::UAshenMechanicalHonestyEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMechanicalHonestyEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenMechanicalHonestyEvaluatorComponent::ValidateFrameDataIntegrity(bool bCanonicalEventRecorded, bool bCharacterBelievesInSolo)
{
	// Even if Kaelen subjectively believes he fought alone, canonical ground truth preserves unlocked frame data!
	const bool bIntegrityMaintained = bCanonicalEventRecorded;
	UE_LOG(LogTemp, Log, TEXT("UAshenMechanicalHonestyEvaluatorComponent: Mechanical Integrity: %s (Subjective Solo Belief: %s)"),
		bIntegrityMaintained ? TEXT("PRESERVED") : TEXT("LOST"), bCharacterBelievesInSolo ? TEXT("TRUE") : TEXT("FALSE"));
	return bIntegrityMaintained;
}
